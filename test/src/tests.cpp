#include "gtest/gtest.h"
#include <KiviJson.h>
#include <vector>

using namespace KiviJson;

class JsonTest : public ::testing::Test {

protected:
  std::vector<const char *> jsons = {"", " ", " null", " true", "false"};
  std::vector<JsonType> results = {JsonType::TYPE_NULL, JsonType::TYPE_NULL,
                                   JsonType::TYPE_NULL, JsonType::TYPE_BOOL,
                                   JsonType::TYPE_BOOL};
  virtual void SetUp(){};
  virtual void TearDown(){};

  virtual void verify(int index) {
    EXPECT_EQ(JsonObject::parse(jsons[index])->type, results[index]);
  }
};

TEST_F(JsonTest, test_empty) { verify(0); }
TEST_F(JsonTest, test_white) { verify(1); }
TEST_F(JsonTest, test_null) { verify(2); }
TEST_F(JsonTest, test_true) { verify(3); }
TEST_F(JsonTest, test_false) { verify(4); }
