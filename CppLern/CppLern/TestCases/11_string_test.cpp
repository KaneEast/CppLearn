#include "all.h"
using namespace std;

namespace string_test {
    /**
     改行 \n
     水平タブ \t
     垂直タブ \v
     バックスペース \b
     キャリッジリターン \r
     フォームフィード \f
     アラート \a
     バックスラッシュ \\
     疑問符 \?
     単一引用符 \'
     二重引用符 \"
     */

    const char s4[4] = {'a', 'b', 'c', '\0'} ;
    const char s6[6] = {'h', 'e', 'l', 'l', 'o', '\0' } ;

    char s66[6] = "hello" ;
    // char [6]
    char s666[] = "hello" ;
    const char * p = "hello" ;

    // const char *
    auto pointer = "hello" ;

    // decltype(auto)というautoと似ているがあまり暗黙の型変換を行わない別のキーワードを使うと、配列へのリファレンス型になる。
    // const char (&) [6]
    decltype(auto) reference = "hello" ;


    char     utf8   = u8'a' ;
    char16_t utf16  = u'あ' ;
    char32_t utf32  = U'あ' ;


    // char8_t [10]
    char s11[] = u8"いろは" ;
    // char16_t [4]
    char16_t s22[] = u"いろは" ;
    // char32_t [4]
    char32_t s33[] = U"いろは" ;

    char s111[10]    = { (char)0xe3, (char)0x81, (char)0x84, (char)0xe3, (char)0x82, (char)0x8d, (char)0xe3, (char)0x81, (char)0xaf, (char)0x0 } ;
    char16_t s222[4] = { 0x3044, 0x308d, 0x306f, 0x0 } ;
    char32_t s333[4] = { 0x3044, 0x308d, 0x306f, 0x0 } ;

    string rawstr = R"('は単一引用符
        "は二重引用符
\nは改行文字     \nは改行文字     \nは改行文字
    )" ;

    
    // strが指す配列のサイズを取得
    auto str_size = std::strlen( pointer ) ;

    
    std::size_t strlen( const char * s )
    {
        auto i = s ;
        while ( *i != '\0' )
        { ++i ; }
        return i - s ;
    }

    // s1, s2を結合して使う関数
    void concat_str( const char *  s1, const char * s2 )
    {
        // 2つの文字列のサイズの合計 + null文字
        auto size = std::strlen( s1 ) + std::strlen( s2 ) + 1 ;
        // 文字列を保持するメモリーを確保する
        char * ptr = new char[size] ;

        char * i = ptr ;
        // s1をコピー
        while ( *s1 != '\0' )
        {
            *i = *s1 ;
            ++i ; ++s1 ;
        }
        // s2をコピー
        while ( *s2 != '\0' )
        {
            *i = *s2 ;
            ++i ; ++s2 ;
        }
        // null終端する
        *i = '\0' ;

        // 結合した文字列を使う

        // 使い終わったのでメモリーを解放する
        delete[] ptr ;
    }

    // C++20
    void basic_string_view_test()
    {
//        auto text = "quick brown fox jumps over the lazy dog." ;
//        text.remove_prefix( "quick "sv.size() ) ;
//        // textは"brown fox jumps over the lazy dog."
//        text.remove_prefix( "brown"sv.size() ) ;
//        // textは"fox jumps over the lazy dog."

//        auto text = "quick brown fox jumps over the lazy dog." ;
//        text.remove_suffix( " dog."sv.size() ) ;
//        // textは"quick brown fox jumps over the lazy"
//        text.remove_suffix( " lazy".sv.size() ) ;
//        // textは"quick brown fox jumps over the"
        
    }
}

void step11_string_test()
{
    cout << string_test::rawstr;
    cout << string_test::str_size;
}





