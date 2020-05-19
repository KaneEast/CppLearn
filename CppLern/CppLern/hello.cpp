//
//  hello.cpp
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 Kane. All rights reserved.
//


// GCCを使って先ほどのhello.cppをコンパイルするには以下のようにする。
// $ g++ -o hello hello.cpp

#include <iostream>
using namespace std;

extern void lammda_test();
extern void standardInput_test();
extern void input_redirect();
extern void recursion_test();



#define TESTinput_redirect 0

int main(int argc, const char * argv[]) {
    
#if !TESTinput_redirect
    lammda_test();
//    standardInput_test();
    recursion_test();
#else
    input_redirect();
#endif
    
    
    cout << __cplusplus << endl;
    
    return 0;
}
