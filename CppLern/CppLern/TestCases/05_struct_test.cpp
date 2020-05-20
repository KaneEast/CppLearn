#include "all.h"
using namespace std;

struct S
{
    int a ;
    double b ;
    std::string c ;
};

struct IntLike
{
    int data {} ;

    // 前置
    IntLike & operator ++()
    {
        ++data ;
        return *this ;
    }
    // 後置
    IntLike operator ++(int)
    {
        IntLike copy = *this ;
        ++*this ;
        return copy ;
    }
} ;

void step05_struct_test()
{
    S a{123, 1.23, "123"} ;
    
    cout << a.a << " " << a.b << " " << a.c << endl;
}
