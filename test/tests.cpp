#include <gtest.h>

#include "header.h"

TEST(test_ConfromRoman, test_one)
{
    roman r;
    r.val = "I";
    Convertor con;

    con.toArabic(r);

    EXPECT_EQ(1, con.get_a_struct());
}

TEST(test_ConfromRoman, test_five)
{
    roman r;
    r.val = "V";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(5, con.get_a_struct());
}

TEST(test_ConfromRoman, test_ten)
{
    roman r;
    r.val = "X";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(10, con.get_a_struct());
}

TEST(test_ConfromRoman, test_fifty)
{
    roman r;
    r.val = "L";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(50, con.get_a_struct());
}

TEST(test_ConfromRoman, test_hundred)
{
    roman r;
    r.val = "C";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(100, con.get_a_struct());
}

TEST(test_ConfromRoman, test_five_hundred)
{
    roman r;
    r.val = "D";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(500, con.get_a_struct());
}

TEST(test_ConfromRoman, test_thousand)
{
    roman r;
    r.val = "M";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(1000, con.get_a_struct());
}

TEST(test_ConfromRoman, test_three)
{
    roman r;
    r.val = "III";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(3, con.get_a_struct());
}

TEST(test_ConfromRoman, test_four)
{
    roman r;
    r.val = "IV";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(4, con.get_a_struct());
}

TEST(test_ConfromRoman, test_eight)
{
    roman r;
    r.val = "VIII";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(8, con.get_a_struct());
}

TEST(test_ConfromRoman, test_nine)
{
    roman r;
    r.val = "IX";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(9, con.get_a_struct());
}

TEST(test_ConfromRoman, test_fourty_four)
{
    roman r;
    r.val = "XLIV";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(44, con.get_a_struct());
}

TEST(test_ConfromRoman, test_one_thousand_nine_hundred_sixty_eight)
{
    roman r;
    r.val = "MCMLXVIII";
    Convertor con;

    con.toArabic(r);
    EXPECT_EQ(1968, con.get_a_struct());
}

TEST(test_ConfromArabic, test_one)
{
    arabic a;
    a.val = 1;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("I", con.get_r_struct());
}

TEST(test_ConfromArabic, test_five)
{
    arabic a;
    a.val = 5;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("V", con.get_r_struct());
}

TEST(test_ConfromArabic, test_ten)
{
    arabic a;
    a.val = 10;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("X", con.get_r_struct());
}

TEST(test_ConfromArabic, test_fifty)
{
    arabic a;
    a.val = 50;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("L", con.get_r_struct());
}

TEST(test_ConfromArabic, test_hundred)
{
    arabic a;
    a.val = 100;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("C", con.get_r_struct());
}

TEST(test_ConfromArabic, test_five_hundred)
{
    arabic a;
    a.val = 500;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("D", con.get_r_struct());
}

TEST(test_ConfromArabic, test_thousand)
{
    arabic a;
    a.val = 1000;
    Convertor con;

    con.toRoman(a);
    EXPECT_EQ("M", con.get_r_struct());
}

TEST(noob, test_of_noob)
{
    for (int i = 1; i <= 10000; i++)
    {
        arabic a;
        roman r;
        Convertor con1, con2;

        a.val = i;
        con1.toRoman(a);
        r.val = con1.get_r_struct();
        con2.toArabic(r);

        EXPECT_EQ(i, con2.get_a_struct());
    }
}