#pragma once

namespace KiviJson {
enum class JsonType {
  TYPE_NULL,
  TYPE_BOOL,
  TYPE_NUMBER,
  TYPE_STRING,
  TYPE_ARRAY,
  TYPE_OBJECT
};

class JsonObject {
public:
  JsonObject(JsonType jsonType);
  JsonType type;
  static JsonObject* parse(const char *json);
};
} // namespace KiviJson