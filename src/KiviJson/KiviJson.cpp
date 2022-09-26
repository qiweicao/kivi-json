#include "KiviJson.h"
#include <assert.h>
#include <cctype>
#include <stdexcept>
#include <string_view>

using namespace KiviJson;

struct JsonContext {
  std::string_view *jsonView;
  int jsonIndex = 0;
};

void parsewhiteSpace(JsonContext *jsonContext) {
  while (std::isspace(jsonContext->jsonView->at(jsonContext->jsonIndex))) {
    jsonContext->jsonIndex++;
  }
  if (jsonContext->jsonIndex >= jsonContext->jsonView->size()) {
    throw std::logic_error("KiviJson: invalid format");
  }
}

JsonType parseNull(JsonContext *jsonContext) {
  if (jsonContext->jsonView->compare(jsonContext->jsonIndex, 4, "null") == 0) {
    jsonContext->jsonIndex += 4;
  }
  return JsonType::TYPE_NULL;
}

JsonObject::JsonObject(JsonType jsonType) { this->type = jsonType; }

JsonObject *JsonObject::parse(const char *json) {
  const auto jsonView = new std::string_view(json);
  auto jsonContext = new JsonContext();
  jsonContext->jsonView = jsonView;
  const auto type = parseNull(jsonContext);
  return new JsonObject(type);
}
