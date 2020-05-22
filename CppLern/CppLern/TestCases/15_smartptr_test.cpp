#include "all.h"
using namespace std;

namespace smartptr_test
{
    // test unique ptr
    void test1()
    {
        auto p = std::make_unique< int >( 0 ) ;

        *p = 123 ;
        std::cout << *p ;
        
        auto pv = std::make_unique< std::vector<int> > () ;
        pv->push_back(0) ;
    }


    // 古臭い時代遅れの生ポインターを引数に取る関数
    void old_outdated_ugly_function( int * ptr )
    {
    }

    void test2()
    {
        auto ptr = std::make_unique<int>(0);
        old_outdated_ugly_function(ptr.get());
    }



    int * last_ptr ;
    bool is_equal_to_last_ptr( int * ptr )
    {
        if ( last_ptr == nullptr )
            last_ptr = ptr ;

        bool b =  *ptr == *last_ptr ;
        last_ptr = ptr ;
        return b ;
    }

    void f()
    {
        auto p = std::make_unique<int>(0) ;
        cout << is_equal_to_last_ptr( p.get() ) << endl;
    }

    void test3()
    {
        f() ;
        
        // エラー
        //これは関数fがunique_ptrの寿命の期間を超えてポインターを保持して参照しているからだ。
        //unique_ptrはコピーができない。
        f() ;
        
        
        auto p = std::make_unique<int>(0) ;
        // エラー、コピーはできない
        //auto q = p ;
    }



    void test4()
    {
        auto p1 = std::make_shared<int>(0) ;
        auto p2 = p1 ;
        auto p3 = p1 ;
        
        *p1 = 123;
        cout << *p1 << *p2 << *p3 << endl;
    }





    template < typename T >
    class shared_ptr
    {
        T * ptr = nullptr ;
        std::size_t * count = nullptr ;

        void release()
        {
            if ( count == nullptr )
                return ;

            --*count ;
            if ( *count == 0 )
            {
                delete ptr ;
                ptr = nullptr ;
                delete count ;
                count = nullptr ;
            }
        }
    public :

        shared_ptr() { }
        explicit shared_ptr( T * ptr )
            : ptr(ptr), count( new std::size_t(1) )
        { }
        ~shared_ptr()
        {
            release() ;
        }

        shared_ptr( const shared_ptr & r )
            : ptr( r.ptr ), count( r.count )
        {
            ++*count ;
        }
        shared_ptr & operator =( const shared_ptr & r )
        {
            if ( this == &r )
                return *this ;

            release() ;
            ptr = r.ptr ;
            count = r.count ;
            ++*count ;
        }

        shared_ptr( shared_ptr && r )
            : ptr(r.ptr), count(r.count)
        {
            r.ptr = nullptr ;
            r.count = nullptr ;
        }

        shared_ptr & operator =( shared_ptr && r )
        {
            release() ;
            ptr = r.ptr ;
            count = r.count ;
            r.ptr = nullptr ;
            r.count = nullptr ;
        }

        T & operator * () noexcept { return *ptr ; }
        T * operator ->() noexcept { return ptr ; }
        T * get() noexcept { return ptr ; }
    } ;
}

void step15_smartptr_test()
{
    int * ptr = new int(0) ;
    delete ptr ;
    
    
    int * p1 = new int(0) ;
    int * p2 = new int(1) ;

    delete p2 ;
    delete p1 ;
    
    smartptr_test::test1();
    smartptr_test::test2();
    smartptr_test::test3();
    smartptr_test::test4();
}


