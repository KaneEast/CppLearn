//
//  input_redirect.cpp
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 USER. All rights reserved.
//

#include <iostream>
using namespace std;

void input_redirect()
{
    cout << "input_redirect=====================================BEGIN" << endl;
    
    double height{ } ;
    double mass { } ;

    std::cin >> height >> mass ;

    std::cout << mass / (height*height) ;
    
    
    cout << "input_redirect=====================================END" << endl;
}
