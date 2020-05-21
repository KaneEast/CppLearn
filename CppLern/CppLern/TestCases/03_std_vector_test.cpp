#include "all.h"
using namespace std;

auto output_all = []( auto first, auto last )
{
    for ( auto iter = first ; iter != last ; ++iter )
    {
        std::cout << *iter << "\n"s ;
    }
} ;


void step03_vector_test()
{
    std::vector<int> v = {1,2,3,4,5} ;
    
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << "\n"s ;
    }
    
    for ( std::size_t i = 0 ; i != std::size(v) ; ++i )
    {
        std::cout << v.at(i) << "\n"s ;
    }
    
    output_all(std::begin(v), std::end(v));
}


