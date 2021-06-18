#include <iostream>
#include <ctime>

#include "string_without_mv.h"
#include "string_with_mv.h"

int main()
{
    constexpr int n = 100000;

    { // Without move constructor
        clock_t startTime = std::clock();
        for (int i = 0; i < n; i++)
        {
            StringWithoutMove s1 = "Loooooooooooooooooooooooooooong string";
            StringWithoutMove s2 = s1;
        }
        clock_t endTime = std::clock();

        clock_t resultTime = endTime - startTime;

        std::cout << "Without move constructor: " << resultTime << " ms" << std::endl;
    }

    { // With move constructor
        clock_t startTime = std::clock();
        for (int i = 0; i < n; i++)
        {
            StringWithMove s1 = "Loooooooooooooooooooooooooooong string";
            StringWithMove s2 = std::move(s1);
        }
        clock_t endTime = std::clock();

        clock_t resultTime = endTime - startTime;

        std::cout << "With move constructor: " << resultTime << " ms" << std::endl;
    }

    return 0;
}