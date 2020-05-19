//
//  operator_overloading_test.cpp
//  CppLern
//
//  Created by USER on 2020/05/19.
//  Copyright © 2020 USER. All rights reserved.
//

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


// 単項演算子
struct IntLike{
    int data ;
    
    IntLike operator +( IntLike const & right )
    {
        return IntLike { data + right.data } ;
    }
} ;

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



void operator_overloading_test()
{
    cout << "operator_overloading_test=====================================BEGIN" << endl;
    
    fractional a{ 1, 2 }, b{ 3, 4};
    auto c = a + b ;
    
    cout << c.denom << " " << c.num;
    
    
    cout << "operator_overloading_test=====================================END" << endl;
}
