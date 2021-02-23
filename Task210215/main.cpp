/*
  Author: Brekhuntsov Nikita Aleksandrovich
  Date: 18.02.2021
*/

//                            Solutions                             //
/*********************************************************************
  1)
    * 1.1) complex.h complex.cpp
    * 1.2) vector4d.h vector4d.cpp
    * 1.3) amperage.h amperage.cpp
    * 1.4) position.h position.cpp offset.h offset.cpp
  2) vector2d.h vector2d.cpp
  3) 
    * 3.1) vector<T> because the sequence of moves is a changing set.
    * 3.2) Didn't understand the wording.
  4)
    * 4.1) set<T>
    * 4.2) vector<T>
  5)
    * 5.1) power.h power.cpp
    * 5.2) pressure.h pressure.cpp
    * 5.3) area.h area.cpp
    * 5.4) physical_quantity.h physical_quantity.cpp
    * 5.5) power.h power.cpp area.h area.cpp pressure.h pressure.cpp
    * 5.6) physical_quantity.h physical_quantity.cpp
  6) main.cpp
***********************************************************************/

#include <iostream>

#include "position.h"
#include "offset.h"

template<class T>
T* bubbleSort(T* arr, bool (*cmp)(const T& first, const T& second), int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (cmp(arr[i], arr[j]))
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

int main()
{
    using namespace Chess;

    int* arr = new int[5]{ 1, 5, 3, 2, 1 };

    auto i_cmp = [](const int& first, const int& second) { return first > second; };

    bubbleSort<int>(arr, i_cmp, 5);

    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    Position p1(Position::Horizontal::A, Position::Vertical::One);
    Position p2(Position::Horizontal::B, Position::Vertical::Five);

    Offset o = Offset::calculate(p1, p2);

    std::cout << o.horizontal() << ' ' << o.vertical() << std::endl; // 1 4

    return 0;
}
