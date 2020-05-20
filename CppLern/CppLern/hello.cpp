//
//  hello.cpp
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 Kane. All rights reserved.
//


// GCCを使ってhello.cppをコンパイルするには以下のようにする。
// $ g++ -o hello hello.cpp

#include <iostream>
using namespace std;

extern void lammda_test();
extern void standardInput_test();
extern void input_redirect();
extern void recursion_test();
extern void vector_test();
extern void std_algorithm();
extern void struct_test();
extern void operator_overloading_test();

int main(int argc, const char * argv[]) {
    
    // 1
    // standardInput_test();
    
    // 2
    // lammda_test();
    
    // 3
    // recursion_test();
    
    // 4
    // vector_test();
    
    // 5
    //    std_algorithm();
    
    // 6
    //    struct_test();

    // 7
    operator_overloading_test();
    
    // 8
    // input_redirect();

    
    
    
    // コンパイラのバージョンを確認
    cout << "cplusplus compiler version is: " <<  __cplusplus << endl;
    
    return 0;
}
