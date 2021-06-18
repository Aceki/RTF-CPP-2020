#include <iostream>

#include "not_implemented_exception.h"
#include "area.h"
#include "pressure.h"
#include "force.h"

int main()
{
    using namespace Physics;
    using namespace std;

    Area a1 = 2;
    Area a2 = 23.1;

    Force f1 = 10.3;
    Force f2 = 2.55;

    cout << f1 + f2 << endl; // 12.85 N

    try 
    {
        cout << f1 * f2 << endl;
    }
    catch(Exception exp) // NotImplementedException
    {
        cout << exp.what() << endl; 
    }

    try
    {
        cout << a1 + f1 << endl;
    }
    catch(Exception exp) // LogicException
    {
        cout << exp.what() << endl; 
    }
    

    cout << a1 + a2 << endl; // 25.1 M2

    return 0;
}