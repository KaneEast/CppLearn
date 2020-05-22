#include "all.h"
using namespace std;


namespace pointertest {
    void test1()
    {
        int * pointer ;

        
        std::cout << pointer << endl;
        // 未定義の挙動
        // std::cout << *pointer ; // couse error

        // 未定義の挙動
        
        // disable warning for: [Variable 'pointer' is uninitialized when used here]
        #pragma GCC diagnostic ignored "-Wuninitialized"
        *pointer = 123 ; // Variable 'pointer' is uninitialized when used here
    }

    void test2()
    {
        // intへのポインター型
        using t1 = int * ;
        // doubleへのポインター型
        using t2 = double * ;
        // std::stringへのポインター型
        using t3 = std::string * ;
        // std::array<int,5>へのポインター型
        using t4 = std::array<int,5> * ;
        // std::array<double,10>へのポインター型
        using t5 = std::array<double,10> * ;
    }

    void test3()
    {
        // int型へのポインター型
        using t1 = int * ;
        // int型へのリファレンス型
        using t2 = int & ;
        // どちらも同じconstなint型
        using t3 = const int ;
        using t4 = int const ;
        
        // int *型へのリファレンス
        using type = int * & ;
        
        // エラー、できない
        // using error = int & * ;
        
        
        int * ptr = nullptr ;
        // ptrを参照する
        int * & ref = ptr ;

        int data { } ;
        // ptrの値が&dataになる。
        ref = &data ;
        
        
        // 型T
        using T = int ;
        // どちらもconstなT
        using const_T_1 = const T ;
        using const_T_2 = T const ;
        // Tへのポインター
        using T_pointer = T * ;

        // どちらもconstなTへのポインター
        using const_T_pointer_1 = const T * ;
        using const_T_pointer_2 = T const * ;

        // Tへのconstなポインター
        using T_const_pointer = T * const ;

        // どちらもconstなTへのconstなポインター
        using const_T_const_pointer_1 = const T * const ;
        using const_T_const_pointer_2 = T const * const ;
    }


    int f( int ) ;
    double g( double, double ) ;
    
    void test4_pointerToFunc()
    {
        using f_type = int ( int ) ;
        using g_type = double ( double, double ) ;
        
        using f_pointer = f_type * ;
        using g_pointer = g_type * ;
    }


    int f( int x )
    {
        std::cout << x ;
        return x ;
    }
    void test5()
    {
        using f_type = int ( int ) ;
        using f_pointer = f_type * ;

        f_pointer ptr = &f ;

        // 関数へのポインターを経由した関数呼び出し
        (*ptr)(123) ;
    }

    void test6()
    {
        // 適当な関数
        // int f( int x ) { return 0; }

        // 変数ptrの宣言
        // int (int)へのポインター
        #pragma GCC diagnostic ignored "-Wunused"
        int (*ptr)(int) = &f ;
        
        
        // int f       (int x) { return 0; }
        // int (*ptr)  (int)    = &f ;
    }

    // pointer_to_array
    void test7()
    {
        using pointer_to_array_type = int (*)[5] ;
        
        int a[5] ;
        
//        #pragma GCC diagnostic ignored "-Wunused-result"
        #pragma GCC diagnostic ignored "-Wunused"
        pointer_to_array_type ptr = &a ;
        
        // エイリアス宣言を使わない変数の宣言は以下のようになる。
        int (*p)[5] = &a ;
    }




    // ポインターのサイズ
    template <typename T >
    void print_size()
    {
        std::cout << sizeof(T) << "\n"s ;
    }


    // print pointer size
    void test8()
    {
        print_size<int *>() ;
        print_size<double *>() ;

        // ポインターへのポインター
        print_size<int **>() ;
        
        std::cout << sizeof( std::uintptr_t ) ;
    }


    // C++ 20
    // 生のアドレスを出力する関数
    template < typename T >
    void print_raw_address( T ptr )
    {
        // std::cout << std::bit_cast<std::uintptr_t>(ptr) << "\n"s ;
    }



    /*
     std::byte型

     void *型はアドレスだけを意味するポインター型なので、参照することができない。memcpyの実装にはポインターを経由して参照先を1バイトずつ読み書きする必要がある。そのための型としてstd::byteがある。

     std::byte型は1バイトを表現するための型だ。sizeof(std::byte)の結果は1になる。
     */
    // memcpyの実装
    void * memcpy( void * dest, void const * src, std::size_t n )
    {
        // destをstd::byte *型に変換
        auto d = static_cast<std::byte *>(dest) ;
        // srcをstd::byte const *型に変換する
        auto s = static_cast<std::byte const *>(src) ;

        // srcからnバイトコピーするのでnバイト先のアドレスを得る
        auto last = s + n ;

        // nバイトコピーする
        while ( s != last )
        {
            *d = *s ;
            ++d ;
            ++s ;
        }

        // destを返す
        return dest ;
    }
}





void step09_pointer_test()
{
    pointertest::test8();
    
    
    
//    // C++ 20 tests
//    int data[3] = {0,1,2} ;
//    pointertest::print_raw_address( &data[0] ) ;
//    pointertest::print_raw_address( &data[1] ) ;
//    pointertest::print_raw_address( &data[2] ) ;
    
}
