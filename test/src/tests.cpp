#include "gtest/gtest.h"
#include <KiviJson.h>

class JsonTest : public ::testing::Test {
protected:
  virtual void SetUp(){};

  virtual void TearDown(){};

  virtual void verify(int index) { EXPECT_EQ(1, 1); }
};

TEST_F(JsonTest, test_name) { verify(0); }