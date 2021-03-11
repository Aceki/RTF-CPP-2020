#include <iostream>

#include "area.h"
#include "pressure.h"
#include "power.h"

int main()
{
    using namespace Physics;
    using namespace std;

    Area a1 = 2; // 0
    Area a2 = 23.1;

    cout << a1 + a2 << endl; // 25.1 M2

    return 0;
}