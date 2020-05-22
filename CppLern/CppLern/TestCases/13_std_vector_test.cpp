#include "all.h"
using namespace std;

namespace std_vector_test
{
    // C++ 20
    template < typename T >
    void f()
    {
//        // すでに動的確保した古いストレージ
//        auto old_ptr = new T ;
//
//        // いま構築した新しいストレージ
//        auto new_ptr = new T ;
//
//        // 関数fを抜けるときに古いストレージを解放する。
//        std::scope_exit e( [&]{ delete old_ptr ; } ) ;
//
//        // 古いストレージから新しいストレージにコピー
//        // *new_ptr = *old_ptr ;
//
//        // 変数eの破棄に伴って古いストレージが解放される
    }


    void test1()
    {
        std::vector<int> v(100, 123) ;
        v[0] ; // 123
        v[12] ; // 123
        v[68] ; // 123
        
        
        v.resize(10) ;
        v.size() ; // 10
        // 減らす
        v.resize(5) ;
        v.size() ; // 5
        
        
        v.resize(3, 123) ;
        // vは{123,123,123}
        
        
        v = {1,2,3,4,5} ;
        v.resize(3) ;
        // vは{1,2,3}
        
        
        v = {};
        // vは{}
        v.push_back(1) ;
        // vは{1}
        v.push_back(2) ;
        // vは[1,2}
        v.push_back(3) ;
        // vは{1,2,3}
        
        
        v = {};
        // 少なくとも3個の要素を追加できるように動的メモリー確保
        v.reserve(3) ;
        v.size() ; // 0
        v.capacity() ; // 3以上

        // 動的メモリー確保は発生しない
        v.push_back(1) ;
        v.push_back(2) ;
        v.push_back(3) ;
        // 動的メモリー確保が発生する可能性がある。
        v.push_back(3) ;
    }

    // std::move
    void test2()
    {
        std::vector<int> v ;

        std::vector<int> w = {1,2,3,4,5} ;
        // ムーブ
        v = std::move(w) ;
        // このあとwは使えない

        std::for_each( std::begin(v), std::end(v),
            []( auto x ){
                std::cout << x ;
            } ) ;
        
        // 要素数5
        w.resize(5) ;
        // 妥当に使える
        w[0] = 1 ;
        
        cout << w[0] << endl;
        
    }
}

void step13_std_vector_test()
{
    std_vector_test::f<int>();
    
    std_vector_test::test2();
}
