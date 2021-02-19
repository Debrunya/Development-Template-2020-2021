#include "roman.h"

#include <gtest.h>


TEST(test_convertor, test_one)
{
  arabic v  = toArabic("I");
  EXPECT_EQ(1, v);
}

TEST(test_convertor, test_five)
{
  arabic v = toArabic("V");
  EXPECT_EQ(5, v);
}

TEST(test_convertor, test_four)
{
  arabic v = toArabic("IV");
  EXPECT_EQ(4, v);
}

TEST(test_convertor, test_seven)
{
  arabic v = toArabic("VII");
  EXPECT_EQ(7, v);
}

TEST(test_convertor, test_twelve)
{
  arabic v = toArabic("XII");
  EXPECT_EQ(12, v);
}
