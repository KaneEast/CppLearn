#include <iostream>
using namespace std;

void step00_standardInput_test()
{
    // 入力を受け取るための変数
    std::string x{} ;
    std::string y{} ;
    // 変数に入力を受け取る
    std::cin >>  x >> y ;
    std::cout << x << y << endl;
}
