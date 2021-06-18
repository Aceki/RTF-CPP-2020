#include <gtest/gtest.h>

#include "example_class.h"
#include "unique_pointer.h"

using Pointers::UniquePointer;

TEST(UniquePointerTests, Get_Should_Return_Nullptr_When_Release) 
{
    UniquePointer<ExampleClass> uptr(new ExampleClass(0));

    ExampleClass* obj = uptr.release();

    ASSERT_EQ(uptr.get(), nullptr);
}

TEST(UniquePointerTests, Swap_Should_Work_Correct) 
{
    ExampleClass* exp1 = new ExampleClass(1);
    ExampleClass* exp2 = new ExampleClass(2);

    UniquePointer<ExampleClass> uptr1(exp1);
    UniquePointer<ExampleClass> uptr2(exp2);

    uptr1.swap(uptr2);

    ASSERT_EQ(uptr1.get(), exp2);
    ASSERT_EQ(uptr2.get(), exp1);
}

TEST(UniquePointerTests, MoveConstructor_Should_Work_Correct) 
{
    UniquePointer<ExampleClass> uptr1(new ExampleClass(1));
    UniquePointer<ExampleClass> uptr2 = std::move(uptr1);

    ASSERT_EQ(uptr1.get(), nullptr);
    ASSERT_NE(uptr2.get(), nullptr);
}

TEST(UniquePointerTests, MoveOperator_Should_Work_Correct) 
{
    UniquePointer<ExampleClass> uptr1(new ExampleClass(1));
    UniquePointer<ExampleClass> uptr2; 
    uptr2 = std::move(uptr1);

    ASSERT_EQ(uptr1.get(), nullptr);
    ASSERT_NE(uptr2.get(), nullptr);
}

TEST(UniquePointerTests, CastingEmptyPointerToBool_Should_False) 
{
    UniquePointer<ExampleClass> uptr;

    ASSERT_FALSE((bool)uptr);
}

TEST(UniquePointerTests, CastingNonEmptyPointerToBool_Should_True) 
{
    UniquePointer<ExampleClass> uptr(new ExampleClass(1));

    ASSERT_TRUE((bool)uptr);
}