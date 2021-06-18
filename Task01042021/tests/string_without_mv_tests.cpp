#include <gtest/gtest.h>

#include <stdexcept>

#include "string_without_mv.h"

TEST(StringWithoutMoveTests, Equals_Should_ReturnTrue_When_StringsAreEqual)
{
    StringWithoutMove s1 = "Example string";
    StringWithoutMove s2 = "Example string";

    ASSERT_TRUE(s1.equals(s2));
}

TEST(StringWithoutMoveTests, Equals_Should_ReturnFalse_When_StringsAreNotEqual)
{
    StringWithoutMove s1 = "Example string";
    StringWithoutMove s2 = "String example";

    ASSERT_FALSE(s1.equals(s2));
}

TEST(StringWithoutMoveTests, SumOperator_Should_ReturnConcatenatedString)
{
    StringWithoutMove s1 = "Hello, ";
    StringWithoutMove s2 = "World!";

    StringWithoutMove expected = "Hello, World!";

    ASSERT_TRUE((s1 + s2).equals(expected));

    s1 += s2; // operator+=

    ASSERT_TRUE(s1.equals(expected));
}

TEST(StringWithoutMoveTests, At_Should_ThrowException_When_IndexOutOfRange)
{
    StringWithoutMove s1 = "I love tea!";

    ASSERT_THROW(s1.at(-1), std::out_of_range);
    ASSERT_THROW(s1.at(11), std::out_of_range);
    ASSERT_THROW(s1.at(54), std::out_of_range);
}

TEST(StringWithoutMoveTests, At_ShouldNot_ThrowException_When_IndexInRange)
{
    StringWithoutMove s1 = "Intel";

    ASSERT_NO_THROW(s1.at(0));
    ASSERT_NO_THROW(s1.at(3));
}

TEST(StringWithoutMoveTests, IsEmpty_Should_True_When_Empty)
{
    StringWithoutMove s1 = "";

    ASSERT_TRUE(s1.isEmpty());
}

TEST(StringWithoutMoveTests, IsEmpty_Should_False_When_NotEmpty)
{
    StringWithoutMove s1 = "My name is Potatoman!";

    ASSERT_FALSE(s1.isEmpty());
}

TEST(StringWithoutMoveTests, AssignOperator_Should_Work_Correctly)
{
    StringWithoutMove s1 = "";

    s1 = "One"; // operator=(const char*)

    ASSERT_TRUE(s1.equals("One"));

    s1 = StringWithoutMove("Two"); // operator=(const StringWithoutMove&)

    ASSERT_TRUE(s1.equals("Two"));
}

TEST(StringWithoutMoveTests, Length_Should_Word_Correctly)
{
    StringWithoutMove s1 = "Visual Studio Code";

    ASSERT_EQ(s1.length(), 18);
}