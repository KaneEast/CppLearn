#include "all.h"
using namespace std;

namespace std_vector_test
{
    struct X
    {
        // コピーコンストラクター
        X( const X & ) = delete ;
        // コピー代入演算子
        X & operator = ( const X & ) = delete ;

        // デフォルトコンストラクター
        X() { }
        // ムーブコンストラクター
        X ( X && ) { }
        
        // ムーブ代入演算子
//        X & operator = ( X && ) {
//            return ;
//        }
    } ;
}

void step14_std_vector_test()
{
    // デフォルト構築できる
    std_vector_test::X a ;
    
    // エラー、コピーできない
    //std_vector_test::X b = a ;
    //b = a ;
    
    
    // OK、ムーブはできる。
    std_vector_test::X c = std::move(a) ;
    
}


