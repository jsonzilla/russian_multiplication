#include "gtest/gtest.h"

#include "rmult.h"

TEST(example, demo)
{
  EXPECT_EQ(6, RMULT::rmult(2, 3));
  EXPECT_EQ(60, RMULT::rmult(6, 10));
  EXPECT_EQ(19800, RMULT::rmult(99, 200));
  EXPECT_EQ(247680, RMULT::rmult(258, 960));
  int i = 1; 
  int j = 100;
  for (; i < 1000, j < 10000; i += 3, j += 4) {
    EXPECT_EQ(i * j, RMULT::rmult(i, j));
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}