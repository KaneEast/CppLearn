#include "all.h"
using namespace std;

struct S
{
    int a ;
    double b ;
    std::string c ;
};

void step05_struct_test()
{
    S a{123, 1.23, "123"} ;
    
    cout << a.a << " " << a.b << " " << a.c << endl;
}
