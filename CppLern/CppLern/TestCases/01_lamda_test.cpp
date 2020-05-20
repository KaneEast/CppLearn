#include <iostream>
using namespace std;

void step01_lammda_test()
{
    auto print = [](auto x) {
        std::cout << x << "\n";
    };
    
    print(123) ;
    print(3.14) ;
    print("hello") ;
    

    auto twice = [](auto x) {
        std::cout << x << " " << x << "\n";
    };
    twice(5);
        

    auto print_two = []( auto x, auto y ) {
        std::cout << x << " "s << y << "\n"s ;
    } ;
    print_two( 1, 2 ) ;
    print_two( "Pi is", 3.14 ) ;
    
    

    auto no_args = []() {
        std::cout << "Nothing.\n" ;
    } ;
    no_args() ;
    
    
    // 変数fをラムダ式で初期化
    auto f = [](){} ;
    // 変数fを関数呼び出し
    f() ;

    // ラムダ式を関数呼び出し
    [](){}() ;
    
    
    cout << "-------------------------" << endl;
    
    auto plus = []( auto x, auto y ) {
        return x + y;
    };

    std::cout
        << plus( 1, 2 ) << "\n"s
        << plus( 1.5, 0.5 ) << "\n"s
        << plus( "123"s, "456"s)
        << endl;
}
