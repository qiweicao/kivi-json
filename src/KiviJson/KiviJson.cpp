#include "KiviJson.h"
#include <assert.h>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string_view>


using namespace KiviJson;

struct JsonContext {
  std::string_view *jsonView;
  int jsonIndex = 0;
};

void parseWhiteSpace(JsonContext *jsonContext) {
  while (jsonContext->jsonIndex < jsonContext->jsonView->size() &&
         std::isspace(jsonContext->jsonView->at(jsonContext->jsonIndex))) {
    jsonContext->jsonIndex++;
  }
}

JsonType parseNull(JsonContext *jsonContext) {
  if (jsonContext->jsonView->compare(jsonContext->jsonIndex, 4, "null") == 0) {
    jsonContext->jsonIndex += 4;
  }
  return JsonType::TYPE_NULL;
}

JsonType parseBool(JsonContext *jsonContext) {
  if (jsonContext->jsonView->compare(jsonContext->jsonIndex, 4, "true") == 0) {
    jsonContext->jsonIndex += 4;
    return JsonType::TYPE_BOOL;
  }
  if (jsonContext->jsonView->compare(jsonContext->jsonIndex, 5, "false") == 0) {
    jsonContext->jsonIndex += 5;
    return JsonType::TYPE_BOOL;
  }
  throw std::logic_error("KiviJson: parse bool error");
}

JsonType parseValue(JsonContext *jsonContext) {
  std::cout << "hello, world!" << jsonContext->jsonIndex
            << jsonContext->jsonView->length() << std::endl;
  if (jsonContext->jsonIndex >= jsonContext->jsonView->length()) {
    return JsonType::TYPE_NULL;
  }
  switch (jsonContext->jsonView->at(jsonContext->jsonIndex)) {
  case 't':
  case 'f':
    return parseBool(jsonContext);
  case 'n':
    return parseNull(jsonContext);
  default:
    throw std::logic_error("KiviJson: invalid value");
  }
}

JsonObject::JsonObject(JsonType jsonType) { this->type = jsonType; }

JsonObject *JsonObject::parse(const char *json) {
  // 判断空字符串
  if (*json == '\0') {
    return new JsonObject(JsonType::TYPE_NULL);
  }
  const auto jsonView = new std::string_view(json);
  std::cout << "hello, world!" << std::endl;
  auto jsonContext = new JsonContext();
  jsonContext->jsonView = jsonView;
  parseWhiteSpace(jsonContext);
  auto type = JsonType::TYPE_NULL;
  type = parseValue(jsonContext);
  return new JsonObject(type);
}
