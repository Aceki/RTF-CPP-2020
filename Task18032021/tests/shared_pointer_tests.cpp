#include <iostream>
#include <gtest/gtest.h>

#include "example_class.h"
#include "shared_pointer.h"

using Pointers::SharedPointer;

TEST(SharedPointerTests, CastingEmptyPointerToBool_Should_False) 
{
    SharedPointer<ExampleClass> sptr;

    ASSERT_FALSE((bool)sptr);
}

TEST(SharedPointerTests, CastingNonEmptyPointerToBool_Should_True) 
{
    SharedPointer<ExampleClass> sptr(new ExampleClass(1));

    ASSERT_TRUE((bool)sptr);
}

TEST(SharedPointerTests, UseCount_Should_WorkCorrect) 
{
    SharedPointer<ExampleClass> sptr1(new ExampleClass(1));
    SharedPointer<ExampleClass> sptr2(sptr1);
    SharedPointer<ExampleClass> sptr3(new ExampleClass(3));

    ASSERT_EQ(sptr1.useCount(), 2);
    ASSERT_EQ(sptr3.useCount(), 1);
}

TEST(SharedPointerTests, Swap_Should_Work_Correct) 
{
    ExampleClass* obj1 = new ExampleClass(1);
    ExampleClass* obj2 = new ExampleClass(2);

    SharedPointer<ExampleClass> sptr1(obj1);
    SharedPointer<ExampleClass> sptr2(sptr1);
    SharedPointer<ExampleClass> sptr3(obj2);

    sptr1.swap(sptr3);

    ASSERT_EQ(sptr1.get(), obj2);
    ASSERT_EQ(sptr1.useCount(), 1);

    ASSERT_EQ(sptr2.get(), obj1);
    ASSERT_EQ(sptr2.useCount(), 2);

    ASSERT_EQ(sptr3.get(), obj1);
    ASSERT_EQ(sptr3.useCount(), 2);
}

TEST(SharedPointerTests, ComparisonOperator_Should_True_When_Copy) 
{
    SharedPointer<ExampleClass> sptr1(new ExampleClass(1));
    SharedPointer<ExampleClass> sptr2(sptr1);

    ASSERT_EQ(sptr1, sptr2); // ASSERT_EQ uses operator ==
}

TEST(SharedPointerTests, CopyConstructor_Should_Increment_Count) 
{
    SharedPointer<ExampleClass> sptr1(new ExampleClass(1));
    SharedPointer<ExampleClass> sptr2 = sptr1;

    ASSERT_EQ(sptr1.useCount(), 2);
}
