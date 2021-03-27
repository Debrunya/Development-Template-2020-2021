#include "Polinom.h"
#include "TMonom.h"

#include <gtest.h>

TEST(test_monom, can_create_monom_if_degree_is_lower_than_the_sum_maximum_degrees)
{
    TNode<int, float> m(7850, 1);
    ASSERT_NO_THROW();
}

TEST(test_monom, can_create_monom_if_degree_is_lower_than_the_maximum_degrees)
{
    TNode<int, float> m(15, 15, 15, 1);
    ASSERT_NO_THROW();
}

TEST(test_monom, cant_create_monom_if_degree_is_greater_than_the_maximum_x_degree)
{
    int n = 0;
    try
    {
        TNode<int, float> m(20, 0, 0, 1);
    }
    catch (logic_error)
    {
        n = 1;
    }
    EXPECT_EQ(1, n);
}

TEST(test_monom, cant_create_monom_if_degree_is_greater_than_the_maximum_y_degree)
{
    int n = 0;
    try
    {
        TNode<int, float> m(0, 20, 0, 1);
    }
    catch (logic_error)
    {
        n = 1;
    }
    EXPECT_EQ(1, n);
}

TEST(test_monom, cant_create_monom_if_degree_is_greater_than_the_maximum_z_degree)
{
    int n = 0;
    try
    {
        TNode<int, float> m(0, 0, 20, 1);
    }
    catch (logic_error)
    {
        n = 1;
    }
    EXPECT_EQ(1, n);
}

TEST(test_monom, correct_degree)
{
    TNode<int, float> m(1, 2, 3, 1);
    EXPECT_EQ(443, m.key);
}

TEST(test_monom, correct_coefficient)
{
    TNode<int, float> m(1, 2, 3, 1);
    EXPECT_EQ(1, m.pData);
}

TEST(test_monom, can_compare_the_monom_for_equality)
{
    TNode<int, float> m1(1, 2, 3, 1);
    TNode<int, float> m2(1, 2, 3, 1);
    EXPECT_EQ(true, m1 == m2);
}

TEST(test_monom, can_compare_the_monom_on_inequality)
{
    TNode<int, float> m1(1, 2, 3, 5);
    TNode<int, float> m2(1, 2, 3, 1);
    EXPECT_EQ(true, m1 != m2);
}

TEST(test_monom, can_compare_the_monom_less)
{
    TNode<int, float> m1(0, 1, 2, 1);
    TNode<int, float> m2(1, 2, 3, 1);
    EXPECT_EQ(true, m1 < m2);
}

TEST(test_monom, can_compare_the_monom_greater)
{
    TNode<int, float> m2(0, 1, 2, 1);
    TNode<int, float> m1(1, 2, 3, 1);
    EXPECT_EQ(true, m1 > m2);
}

TEST(test_monom, can_add_monom)
{
    TNode<int, float> m1(1, 2, 3, 1);
    TNode<int, float> m2(1, 2, 3, 1);
    TNode<int, float> m3(0, 0);

    m3 = m1 + m2;
    EXPECT_EQ(2, m3.pData);
}

TEST(test_monom, cant_add_monom_if_different_degree_of_monom)
{
    TNode<int, float> m1(1, 2, 3, 1);
    TNode<int, float> m2(2, 3, 4, 1);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(test_monom, can_subtract_monom)
{
    TNode<int, float> m1(1, 2, 3, 5);
    TNode<int, float> m2(1, 2, 3, 1);
    TNode<int, float> m3(0, 0);
    m3 = m1 - m2;
    EXPECT_EQ(4, m3.pData);
}

TEST(test_monom, cant_subtract_monom_if_different_degree_of_monom)
{
    TNode<int, float> m1(1, 2, 3, 5);
    TNode<int, float> m2(2, 3, 4, 1);
    ASSERT_ANY_THROW(m1 - m2);
}

TEST(test_monom, can_multiply_monom)
{
    TNode<int, float> m1(1, 2, 3, 5);
    TNode<int, float> m2(1, 2, 3, 1);
    TNode<int, float> m3(2, 4, 6, 5);
    TNode<int, float> m4(0, 0);
    m4 = m1 * m2;
    EXPECT_EQ(m4, m3);
}

TEST(test_monom, cant_multiply_monom_if_resulting_degree_exceeds_the_max)
{
    TNode<int, float> m1(15, 0, 0, 1);
    TNode<int, float> m2(15, 0, 0, 1);
    ASSERT_ANY_THROW(m1 * m2);
}

TEST(test_polinom, can_create_polinom)
{
    Polinom m("x^2+y^2");
    ASSERT_NO_THROW();
}

TEST(test_polinom, can_create_copied_polinom)
{
    Polinom m("x^2+y^2");
    Polinom m1(m);
    EXPECT_EQ(m1, m);
}

TEST(test_polinom, can_assign_polinom)
{
    Polinom m("x^2+y^2");
    Polinom m1;
    m1 = m;

    EXPECT_EQ(m1, m);
}

TEST(test_polinom, can_add_monom)
{
    Polinom p;
    TNode<int, float> m(2, 4, 6, 5);
    p = p + m;
    Polinom p1("5x^2y^4z^6");
    EXPECT_EQ(p, p1);
}

TEST(test_polinom, can_subtract_monom)
{
    Polinom p;
    TNode<int, float> m(2, 4, 6, 5);
    p = p - m;
    Polinom p1("-5x^2y^4z^6");
    EXPECT_EQ(p, p1);
}

TEST(test_polinom, can_multiply_monom)
{
    Polinom p("x^2y^4z^6");
    TNode<int, float> m(2, 4, 6, 5);
    p = p * m;
    Polinom p1("5x^4y^8z^12");
    EXPECT_EQ(p, p1);
}

TEST(test_polinom, can_add_polinom)
{
    Polinom p1("x^2y^4z^6");
    Polinom p2("x^2y^4z^6");
    p1 = p1 + p2;
    Polinom p3("2x^2y^4z^6");
    EXPECT_EQ(p3, p1);
}

TEST(test_polinom, can_subtract_polinom)
{
    Polinom p1("x^2y^4z^6");
    Polinom p2("x^2y^4z^6");
    p1 = p1 - p2;
    Polinom p3("");
    EXPECT_EQ(p3, p1);
}

TEST(test_polinom, can_multiply_polinom)
{
    Polinom p1("5x^2y^4z^6");
    Polinom p2("x^2y^4z^6");
    Polinom p3("5x^4y^8z^12");
    p1 = p2 * p1;
    EXPECT_EQ(p3, p1);
}

TEST(test_polinom, cant_multiply_polinom_if_resulting_degree_exceeds_the_max)
{
    Polinom p1("5x^15y^4z^6");
    Polinom p2("x^5y^4z^6");
    ASSERT_ANY_THROW(p1 * p2);
}
