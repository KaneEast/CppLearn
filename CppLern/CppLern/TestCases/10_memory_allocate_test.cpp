#include "all.h"
using namespace std;

namespace memory_allocate {
    

    void test0()
    {
        try {
            void * ptr = ::operator new( 1 ) ;
            
            if ( ptr == nullptr ) {
                // メモリー確保失敗
                std::abort() ;
                
            } else {
                // メモリー確保成功
                
                ::operator delete(ptr);
            }
            
        } catch ( std::bad_alloc e )
        {
            // メモリー確保失敗
        }
    }

    // 配列版new/delete
    void test1()
    {
        int * int_array_ptr =  new int[5]{1,2,3,4,5} ;
        delete [] int_array_ptr ;
    }


    
}

void step10_memory_allocate_test()
{
    
}
