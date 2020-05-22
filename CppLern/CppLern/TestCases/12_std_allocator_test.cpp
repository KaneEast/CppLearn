#include "all.h"
using namespace std;

namespace std_allocator_test
{
    void test1()
    {
        std::allocator<std::string> a ;
        // 生のメモリー確保
        // std::string [1]分のメモリーサイズ
        std::string * p = a.allocate(1) ;
        // メモリー解放
        a.deallocate( p, 1 ) ;
    }

    // [[nodiscard]]という属性により戻り値を無視すると警告が出る。
    //[[nodiscard]]
    int test2()
    {
        return 0;
    }


    // 明示的なデストラクター呼び出しをする関数テンプレート
    template < typename T >
    void destroy_at( T * location )
    {
        location->~T() ;
    }

    
    void test3()
    {
        std::allocator<std::string> a ;
        // 生のメモリー確保
        // std::string [1]分のメモリーサイズ
        std::string * p = a.allocate(1) ;
        // 構築
        std::string * s = new(p) std::string("hello") ;
        // 明示的なデストラクター呼び出し
        s->~basic_string() ;
        
        // メモリー解放
        a.deallocate( p, 1 ) ;
    }


    void test4()
    {
        
    }
}

void step12_std_allocator_test()
{
    std_allocator_test::test2();
}

