#include <gtest/gtest.h>

#include <stdexcept>

#include "string_with_mv.h"

TEST(StringWithMoveTests, Equals_Should_ReturnTrue_When_StringsAreEqual)
{
    StringWithMove s1 = "Example string";
    StringWithMove s2 = "Example string";

    ASSERT_TRUE(s1.equals(s2));
}

TEST(StringWithMoveTests, Equals_Should_ReturnFalse_When_StringsAreNotEqual)
{
    StringWithMove s1 = "Example string";
    StringWithMove s2 = "String example";

    ASSERT_FALSE(s1.equals(s2));
}

TEST(StringWithMoveTests, SumOperator_Should_ReturnConcatenatedString)
{
    StringWithMove s1 = "Hello, ";
    StringWithMove s2 = "World!";

    StringWithMove expected = "Hello, World!";

    ASSERT_TRUE((s1 + s2).equals(expected));

    s1 += s2; // operator+=

    ASSERT_TRUE(s1.equals(expected));
}

TEST(StringWithMoveTests, At_Should_ThrowException_When_IndexOutOfRange)
{
    StringWithMove s1 = "I love tea!";

    ASSERT_THROW(s1.at(-1), std::out_of_range);
    ASSERT_THROW(s1.at(11), std::out_of_range);
    ASSERT_THROW(s1.at(54), std::out_of_range);
}

TEST(StringWithMoveTests, At_ShouldNot_ThrowException_When_IndexInRange)
{
    StringWithMove s1 = "Intel";

    ASSERT_NO_THROW(s1.at(0));
    ASSERT_NO_THROW(s1.at(3));
}

TEST(StringWithMoveTests, IsEmpty_Should_True_When_Empty)
{
    StringWithMove s1 = "";

    ASSERT_TRUE(s1.isEmpty());
}

TEST(StringWithMoveTests, IsEmpty_Should_False_When_NotEmpty)
{
    StringWithMove s1 = "My name is Potatoman!";

    ASSERT_FALSE(s1.isEmpty());
}

TEST(StringWithMoveTests, AssignOperator_Should_Work_Correctly)
{
    StringWithMove s1 = "";

    s1 = "One"; // operator=(const char*)

    ASSERT_TRUE(s1.equals("One"));

    s1 = StringWithMove("Two"); // operator=(const StringWithMove&)

    ASSERT_TRUE(s1.equals("Two"));
}

TEST(StringWithMoveTests, MoveOperator_Should_Work_Correctly)
{
    StringWithMove s1 = "Move this string";

    StringWithMove s2 = std::move(s1);

    ASSERT_TRUE(s1.isEmpty());

    ASSERT_FALSE(s2.isEmpty());

    ASSERT_EQ(s2.length(), 16);

    ASSERT_TRUE(s2.equals("Move this string"));
}

TEST(StringWithMoveTests, Length_Should_Word_Correctly)
{
    StringWithMove s1 = "Visual Studio Code";

    ASSERT_EQ(s1.length(), 18);
}