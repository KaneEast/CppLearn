//
//  vector_test.cpp
//  CppLern
//
//  Created by USER on 2020/05/19.
//  Copyright © 2020 USER. All rights reserved.
//

#include <iostream>
#include <vector>
#include "all.h"

using namespace std;

auto output_all = []( auto first, auto last )
{
    for ( auto iter = first ; iter != last ; ++iter )
    {
        std::cout << *iter << "\n"s ;
    }
} ;


void vector_test()
{
    cout << "vector_test=====================================BEGIN" << endl;
    
    std::vector<int> v = {1,2,3,4,5} ;

    for ( auto iter = std::begin(v), last = std::end(v) ;
          iter != last ; ++iter )
    {
        std::cout << *iter << "\n"s ;
    }
    
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << "\n"s ;
    }
    
    for ( std::size_t i = 0 ; i != std::size(v) ; ++i )
    {
        std::cout << v.at(i) << "\n"s ;
    }
    
    
    
    
    cout << "vector_test=====================================END" << endl;
}


