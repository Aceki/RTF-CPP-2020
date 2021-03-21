#include <iostream>
#include <gtest/gtest.h>

#include "example_class.h"
#include "shared_pointer.h"

using Pointers::SharedPointer;

TEST(SharedPointerTests, CastingEmptyPointerToBool_Should_False) 
{
    SharedPointer<ExampleClass> sp;

    ASSERT_FALSE((bool)sp);
}

TEST(SharedPointerTests, CastingNonEmptyPointerToBool_Should_True) 
{
    SharedPointer<ExampleClass> sp(new ExampleClass(1));

    ASSERT_TRUE((bool)sp);
}

TEST(SharedPointerTests, UseCount_Should_WorkCorrect) 
{
    SharedPointer<ExampleClass> sp1(new ExampleClass(1));
    SharedPointer<ExampleClass> sp2(sp1);
    SharedPointer<ExampleClass> sp3(new ExampleClass(3));

    ASSERT_EQ(sp1.useCount(), 2);
    ASSERT_EQ(sp3.useCount(), 1);
}

TEST(SharedPointerTests, Swap_Should_Work_Correct) 
{
    ExampleClass* obj1 = new ExampleClass(1);
    ExampleClass* obj2 = new ExampleClass(2);

    SharedPointer<ExampleClass> sp1(obj1);
    SharedPointer<ExampleClass> sp2(sp1);
    SharedPointer<ExampleClass> sp3(obj2);

    sp1.swap(sp3);

    ASSERT_EQ(sp1.get(), obj2);
    ASSERT_EQ(sp1.useCount(), 1);

    ASSERT_EQ(sp2.get(), obj1);
    ASSERT_EQ(sp2.useCount(), 2);

    ASSERT_EQ(sp3.get(), obj1);
    ASSERT_EQ(sp3.useCount(), 2);
}

TEST(SharedPointerTests, ComparisonOperator_Should_True_When_Copy) 
{
    SharedPointer<ExampleClass> sp1(new ExampleClass(1));
    SharedPointer<ExampleClass> sp2(sp1);

    ASSERT_EQ(sp1, sp2); // ASSERT_EQ uses operator ==
}

TEST(SharedPointerTests, CopyConstructor_Should_Increment_Count) 
{
    SharedPointer<ExampleClass> sp1(new ExampleClass(1));
    SharedPointer<ExampleClass> sp2 = sp1;

    ASSERT_EQ(sp1.useCount(), 2); // ASSERT_EQ uses operator ==
}
