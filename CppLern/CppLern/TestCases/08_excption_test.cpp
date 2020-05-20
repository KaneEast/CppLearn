#include "all.h"
using namespace std;

namespace excption_test {
    void test1()
    {
        try {
            throw "error"s ; // std::string型
        }
        // キャッチしない
        catch( int e ) { }
        // キャッチしない
        catch( double e ) { }
        // キャッチする
        catch( std::string & e )
        {
            std::cout << e ;
        }
    }


    void f() { throw 0 ; }
    void g() { f() ; }
    void h() { g() ; }
    void test2()
    {
        try{
            h();
        } catch (int e) {
            cout << e;
        }
    }
}




void step08_excption_test()
{
    excption_test::test1();
    excption_test::test2();
    cout << endl;
}
