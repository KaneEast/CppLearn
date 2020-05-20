#include "all.h"
using namespace std;



//  関数テンプレート---------------------------------------------------------

template <typename T>
T twice(T n)
{
    return n * 2;
}

template <typename T>
void f(T const & x)
{
    std::cout << x;
}


template <int N>
void fi()
{
    std::cout << N;
}

template <std::size_t N>
void fBuffer()
{
    int buffer[N];
}




namespace kg
{
    // イテレータ
    template <typename Array>
    struct array_iterator
    {
        // 参照している配列
        Array & a;
        // 参照しているインデックス
        std::size_t i;

        array_iterator(Array & a, std::size_t i)
            : a(a), i(i)
        {
        }

        // いま参照している要素へのリファレンスを返す
        typename Array::reference operator *()
        {
            return a[i];
        }

        
        array_iterator & operator ++()
        {
            ++i;
            return *this;
        }
        
        array_iterator & operator += ( std::size_t n )
        {
            i += n ;
            return *this ;
        }

        array_iterator operator + ( std::size_t n ) const
        {
            auto copy = *this ;
            copy += n ;
            return copy ;
        }
    };


    // 配列
    template <typename T, std::size_t N>
    struct array
    {
        T storage[N];
        using reference = T &;
        using const_reference = T const &;
        
        
        T & operator [] (std::size_t i)
        {
            return storage[i];
        }

        T& front() { return storage[0]; }
        const T& front() const { return storage[0]; }

        T& back() { return storage[N-1]; }
        const T& back() const { return storage[N-1]; }
        
        void fill(T const & u)
        {
            for (std::size_t i = 0; i != N; ++i)
            {
                storage[i] = u;
            }
        }
        
        
        using iterator = array_iterator<array>;

        // 先頭要素のイテレーター
        iterator begin()
        {
            return array_iterator(*this, 0);
        }

        // 最後の次の要素へのイテレーター
        iterator end()
        {
            return array_iterator(*this, N);
        }

    };

}







void step07_template_array_test()
{
    cout << twice(123) << endl;  // int
    cout << twice(1.23) << endl; // double
    
    
    // Tはint
    f(0);
    // Tはdouble
    f(0.0);
    // Tはstd::string
    f("hello"s);
    
    // Tはdouble
    // int型0からdouble型0.0への変換が行われる
    f<double>(0);
    
    
    
    // Nは0
    fi<0>();
    // Nは123
    fi<123>();
    
    
    
    // テンプレート引数はコンパイル時にすべてが決定される。なのでテンプレート引数に渡せる値はコンパイル時に決定できるものでなければならない。
//    int x{};
//    std::cin >> x;
//    // エラー
//    f<x>();
    
    
    
    // 配列bufferのサイズは10
    fBuffer<10>();
    // サイズは12
    fBuffer<12>();
    
    
    
    
//    using array_type = std::array<int, 5>;
//    array_type a = {1,2,3,4,5};
//    array_type::value_type x = 0;
//    array_type::reference ref = a[0];
    
    
    kg::array<int,5> a = {1,2,3,4,5};

    auto iter = a.begin();

    std::cout << *iter; // 1
    ++iter;
    std::cout << *iter; // 2
}
