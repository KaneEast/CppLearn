//
//  struct_test.cpp
//  CppLern
//
//  Created by USER on 2020/05/19.
//  Copyright © 2020 USER. All rights reserved.
//

#include "all.h"
using namespace std;


struct S
{
    int a ;
    double b ;
    std::string c ;
};


void struct_test()
{
    cout << "struct_test=====================================BEGIN" << endl;
    
    S a{123, 1.23, "123"} ;
    
    cout << a.a << " " << a.b << " " << a.c << endl;
    
    
    
    
    
    
    cout << "struct_test=====================================END" << endl;
}
