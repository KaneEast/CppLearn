#include "all.h"
using namespace std;

namespace kg {
    
    // 要素に1つでも条件を満たすものがあるかどうかを調べるのに使える。
    auto any_of = []( auto first, auto last, auto pred )
    {
        for ( auto iter = first ; iter != last ; ++iter )
        {
            if ( pred( *iter ) )
                return true ;
        }
        return false ;
    } ;

    // 要素がすべて条件を満たすかどうかを調べるのに使える。
    auto all_of = []( auto first, auto last, auto pred )
    {
        for ( auto iter = first ; iter != last ; ++iter )
        {
            if ( pred( *iter ) == false )
                return false ;
        }

        return true ;
    } ;

    // 要素ごとの処理は引数に取った関数に任せている
    auto for_each = []( auto first, auto last, auto f )
    {
        for ( auto iter = first ; iter != last ; ++iter )
        {
            f( *iter ) ;
        }
    } ;

    // すべての要素が条件を満たさない判定に使える。
    auto none_of = []( auto first, auto last, auto pred )
    {
        for ( auto iter = first ; first != last ; ++iter )
        {
            if ( pred(*iter) )
                return false ;
        }
        return true ;
    } ;

    // [first,last)からvalueに等しい値を見つけて、そのイテレーターを返すアルゴリズム
    auto find = []( auto first, auto last, auto const & value )
    {
        for ( auto iter = first ; iter != last ; ++iter )
        {
            // 値を発見したらそのイテレーターを返す
            if ( *iter == value )
                return iter ;
        }
        // 値が見つからなければ最後のイテレーターを返す
        return last ;
    } ;

    // predがtrueを返した最初のイテレーターを返す
    auto find_if = []( auto first, auto last, auto pred )
    {
        for ( auto iter = first ; iter != last ; ++iter )
        {
            if ( pred( *iter ) )
                return iter ;
        }

        return last ;
    } ;

    // [first,last)の範囲のイテレーターiから*i == valueになるイテレーターiの数を数える。
    auto count = []( auto first, auto last, auto value )
    {
        auto counter = 0u ;
        for ( auto i = first ; i != last ; ++i )
        {
            if ( *i == value )
                ++counter ;
        }
        return counter ;
    } ;

    // count_if(first, last, pred)は[first, last)の範囲のイテレーターiからpred(*i) != falseになるイテレーターiの数を返す。
    auto count_if = []( auto first, auto last, auto pred )
    {
        auto counter = 0u ;
        for ( auto i = first ; i != last ; ++i )
        {
            if ( pred(*i) != false )
                ++counter ;
        }
        return counter ;
    } ;

    
}

// C++17
void step04_std_algorithm()
{
    std::vector<int> v = {1,2,3,4,5} ;
    
    // どうやって終わらせるかわからない
    //    std::istream_iterator<int> first( std::cin ), last ;
    //    output_all( first, last ) ;
        
        //directory_iterator' is unavailable: introduced in macOS 10.15
    //    std::filesystem::directory_iterator first("./"), last ;
    //    output_all( first, last ) ;
        
        
        
        
    std::for_each( std::begin(v), std::end(v), []( auto value ) {
        std::cout << value;
    });
    cout << endl;
        
        // C++20予定
    //    std::for_each( v, []( auto value ) {
    //        std::cout << value;
    //    });
    
    
    
    // 引数を出力する関数
    auto print = [](auto & value){ std::cout << value << ", "s ; } ;
    std::for_each( std::begin(v), std::end(v), print);
    
    
    
    bool bb = std::all_of( std::begin(v), std::end(v), [](auto value){
        // 特に意味のない関数
        return value > 0;
    });
    cout << bb << endl;
    
    
    bool has_3 = std::any_of( std::begin(v), std::end(v), []( auto x ) {
        return x == 3;
    });
    cout << has_3 << endl;
    
    
    // 3を指すイテレーター
    auto pos = std::find( std::begin(v), std::end(v), 3 ) ;

    std::cout << *pos ;
    
    
    
    
    // [=]を使うことで、関数の外側の値をコピーして使うことができる。

    int value = 123 ;

    auto f = [=]{ return value ; } ;

    cout << f() ; // 123
    
    
    // [&]を使うことで、関数の外側の値をリファレンスで使うことができる。

    auto fRef = [&]{ ++value ; } ;
    fRef() ;
    std::cout << value ; // 124
    
    
    
    std::vector<int> a = {1,2,3,4,5} ;
    // aと等しい
    std::vector<int> b = {1,2,3,4,5} ;
    // aと等しくない
    std::vector<int> c = {1,2,3,4,5,6} ;
    // aと等しくない
    std::vector<int> d = {1,2,2,4,6} ;

    // true
    bool ab = std::equal(
        std::begin(a), std::end(a),
        std::begin(b), std::end(b) ) ;

    // false
    bool ac = std::equal(
        std::begin(a), std::end(a),
        std::begin(c), std::end(c) ) ;

    // false
    bool ad = std::equal(
        std::begin(a), std::end(a),
        std::begin(d), std::end(d) ) ;
    
    
    // 最初の要素
    auto first = std::begin(v) ;
    // 最後の1つ次の要素
    auto last = std::end(v) ;

    // 要素数: 5
    auto size = std::distance( first, last ) ;
    
    // 4
    auto size_from_next = std::distance( first + 1, last ) ;
    
    
    
    std::vector<double> vv = {1.3, 2.2, 3.0, 4.9, 5.7} ;
    std::vector<double> w = {1.9, 2.4, 3.8, 4.5, 5.0} ;
    
    // 小数点以下は誤差として切り捨てる比較
    auto comp = []( auto a, auto b )
    {
        return std::floor(a) == std::floor(b) ;
    } ;
    
    bool bbb = std::equal(
    std::begin(vv), std::end(vv),
    std::begin(w), std::end(w),
    comp ) ;
    
    
    // search( first1, last1, first2, last2)はイテレーター[first2, last2)の範囲で示された連続した要素の並びがイテレーター
    // [first1, last1)の範囲に存在すればtrue、そうでない場合はfalseを返す。
    std::vector<int> v1 = {1,2,3,4,5,6,7,8,9} ;
    std::vector<int> v2 = {4,5,6} ;

    // true
//    bool aa1 = std::search( std::begin(v1), std::end(v1), std::begin(v2), std::end(v2) ) ;
//
//    std::vector<int> v3 = {1,3,5} ;
//    // false
//    bool aa2 = std::search( std::begin(v1), std::end(v1), std::begin(v3), std::end(v3) ) ;
    
    
    
    std::vector<int> source = {1,2,3,4,5} ;
    // 要素数5のvector
    std::vector<int> destination(5) ;

    std::copy( std::begin(source), std::end(source), std::begin(destination) ) ;

    // destinationの中身は{1,2,3,4,5}
    
    
    
    std::vector<int> aaaa = {1,2,3,4,5} ;

    std::vector<int> bbbb(5) ;
    std::transform( std::begin(aaaa), std::end(aaaa), std::begin(bbbb),
        [](auto x){ return 2*x ; } ) ;
    // bbbbは{2,4,6,8,10}
    
    
    // replace(first, last, old_value, new_value)はイテレーター[first,last)の範囲のイテレーターが指す要素の値が
    // old_valueに等しいものをnew_valueに置換する関数だ。
    std::vector<int> vReplace = {1,2,3,3,4,5,3,4,5} ;
    std::replace( std::begin(vReplace), std::end(vReplace), 3, 0 ) ;
    // aは{1,2,0,0,4,5,0,4,5}
    
    
    std::vector<int> vFill = {1,2,3,4,5} ;
    std::fill( std::begin(vFill), std::end(vFill), 0 ) ;
    // vは{0,0,0,0,0}
    
    
    std::vector<int> vGenerate = {1,2,3,4,5} ;
    auto gen_zero = [](){ return 0 ; } ;
    std::generate( std::begin(vGenerate), std::end(vGenerate), gen_zero ) ;
    // vは{0,0,0,0,0}
    
    
    
    // 偶数の場合true、奇数の場合falseを返す関数
    auto is_even = []( auto x ) { return x%2 == 0 ; } ;

    std::vector vRemoveif = { 1,2,3,4,5,6,7,8,9 } ;
    // 偶数を取り除く
    auto lastvRemoveif = std::remove_if( std::begin(vRemoveif), std::end(vRemoveif), is_even ) ;

    // [ std::begin(v), last)は{1,3,5,7,9}
}
