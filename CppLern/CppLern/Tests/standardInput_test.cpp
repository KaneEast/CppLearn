//
//  standardInput_test.cpp
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 USER. All rights reserved.
//

#include <iostream>
using namespace std;

void standardInput_test()
{
    cout << "standardInput_test=====================================BEGIN" << endl;
    
    // 1
    // 入力を受け取るための変数
    std::string x{} ;
    std::string y{} ;
    // 変数に入力を受け取る
    std::cin >> x ;
    // 入力された値を出力
    std::cout << x << endl;
    
    
    // 2
    std::cin >>  x >> y ;
    std::cout << x << y << endl;
    
    
    cout << "standardInput_test=====================================END" << endl;
}
