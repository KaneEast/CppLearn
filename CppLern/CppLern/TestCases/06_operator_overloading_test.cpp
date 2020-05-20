#include "all.h"
using namespace std;

struct fractional
{
    int num ;
    int denom ;

    // コンストラクター
    fractional( int num, int denom )
        : num(num), denom(1)
    { }
} ;

fractional operator +( fractional & l, fractional & r )
{
    // 分母が同じなら
    if ( l.denom == r.denom )
        // 単に分子を足す
        return fractional{ l.num + r.num, l.denom } ;
    else
        // 分母を合わせて分子を足す
        return fractional{ l.num * r.denom + r.num * l.denom, l.denom * r.denom } ;
}



struct IntLike{
    int data ;
    
    IntLike operator +( IntLike const & right )
    {
        return IntLike { data + right.data } ;
    }
} ;


// 単項演算子
IntLike operator +( IntLike const & obj )
{
    return obj ;
}

IntLike operator -( IntLike const & obj )
{
    return IntLike{ -obj.data } ;
}

IntLike & operator ++( IntLike & obj )
{
    ++obj.data ;
    return obj ;
}
IntLike & operator --( IntLike & obj )
{
    --obj.data ;
    return obj ;
}



void step06_operator_overloading_test()
{
    fractional a{ 1, 2 }, b{ 3, 4};
    auto c = a + b ;
    
    cout << c.denom << " " << c.num;
}
