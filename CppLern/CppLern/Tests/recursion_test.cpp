//
//  recursion_test.cpp
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 USER. All rights reserved.
//

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


void recursion_test()
{
    cout << "recursion_test=====================================BEGIN" << endl;
    
    until_ten(0);
    
    cout << "recursion_test=====================================END" << endl;
}
