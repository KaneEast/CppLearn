#include <iostream>
using namespace std;

void until_ten( int x )
{
    if ( x > 10 )
        return ;
    else
    {
        std::cout << x << "\n" ;
        return until_ten( x + 1 ) ;
    }
}

void step02_recursion_test()
{
    until_ten(0);
}
