#include "gtest/gtest.h"
#include <KiviJson.h>

using namespace KiviJson;

class JsonTest : public ::testing::Test {
protected:
  virtual void SetUp(){};

  virtual void TearDown(){};

  virtual void verify(int index) { EXPECT_EQ(JsonObject::parse("null")->type , JsonType::TYPE_NULL); }
};

TEST_F(JsonTest, test_name) { verify(0); }