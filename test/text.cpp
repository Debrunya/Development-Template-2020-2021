#include "gtest.h"
#include "TText.h"

TEST(test_text, can_create_text)
{
    ASSERT_NO_THROW(Text t);
}

TEST(test_text, correct_creating_root_string_1)
{
    Text t;
    t.addLeft("key:value");

    EXPECT_EQ("key:value", t.getValCurr());
}

TEST(test_text, correct_creating_root_string_2)
{
    Text t;
    t.addRight("key:value");

    EXPECT_EQ("key:value", t.getValCurr());
}

TEST(test_text, cant_move_to_zero_left_branch)
{
    Text t;
    t.addRight("key:value");
    t.addRight("key:value");

    ASSERT_ANY_THROW(t.left());
}

TEST(test_text, can_move_left)
{
    Text t;
    t.addLeft("key:value");
    t.addLeft("key:value");

    ASSERT_NO_THROW(t.left());
}

TEST(test_text, correct_move_left)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addLeft("13:31");
    t.left();

    EXPECT_EQ("13:31", t.getValCurr());
}

TEST(test_text, cant_move_to_zero_right_branch)
{
    Text t;
    t.addLeft("key:value");
    t.addLeft("key:value");

    ASSERT_ANY_THROW(t.right());
}

TEST(test_text, can_move_right)
{
    Text t;
    t.addRight("key:value");
    t.addRight("key:value");

    ASSERT_NO_THROW(t.right());
}

TEST(test_text, correct_move_right)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addLeft("13:31");
    t.right();

    EXPECT_EQ("15:51", t.getValCurr());
}

TEST(test_text, cant_get_above_top)
{
    Text t;
    t.addLeft("key:value");

    ASSERT_ANY_THROW(t.top());
}

TEST(test_text, can_move_top)
{
    Text t;
    t.addRight("key:value");
    t.addRight("key:value");
    t.right();

    ASSERT_NO_THROW(t.top());
}

TEST(test_text, correct_move_top)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addLeft("13:31");
    t.right();
    t.top();

    EXPECT_EQ("12:21", t.getValCurr());
}

TEST(test_text, correct_remove_from_left)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addLeft("13:31");
    t.remove();

    EXPECT_EQ("13:31", t.getValCurr());
}

TEST(test_text, correct_remove_from_right)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("13:31");
    t.right();
    t.remove();
    t.right();

    EXPECT_EQ("15:51", t.getValCurr());
}

TEST(test_text, correct_replace)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("13:31");
    t.right();
    t.replace("14:41");

    EXPECT_EQ("14:41", t.getValCurr());
}

TEST(test_text, correct_replace_key_without_key)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("31");
    t.right();
    t.replaceKey("18");

    EXPECT_EQ("18:31", t.getValCurr());
}

TEST(test_text, correct_replace_key_with_key)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("13:31");
    t.right();
    t.replaceKey("18");

    EXPECT_EQ("18:31", t.getValCurr());
}

TEST(test_text, correct_replace_value_without_key)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("13");
    t.right();
    t.replaceValue("18");

    EXPECT_EQ("18", t.getValCurr());
}

TEST(test_text, correct_replace_value_with_key)
{
    Text t;
    t.addLeft("12:21");
    t.addRight("15:51");
    t.addRight("13:31");
    t.right();
    t.replaceValue("18");

    EXPECT_EQ("13:18", t.getValCurr());
}
