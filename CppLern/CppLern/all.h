//
//  all.h
//  CppLern
//
//  Created by USER on 2020/05/18.
//  Copyright © 2020 USER. All rights reserved.
//

#ifndef all_h
#define all_h

/**
 $ g++ -include all.h -o program main.cpp
 */

#include <cstddef>
#include <limits>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cstdlib>
#include <new>
#include <typeinfo>
#include <exception>
#include <initializer_list>

//https://qiita.com/dynamonda/items/3a2f5bd063cb5e457605
//#include <cstdalign>

#include <stdexcept>
#include <cassert>
#include <cerrno>
#include <system_error>
#include <string>

#if __has_include(<string_view>)
#   include <string_view>
#endif

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>
#include <cfenv>
#include <random>
#include <numeric>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <ios>
#include <streambuf>
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#if __has_include(<filesystem>)
#   include <filesystem>
#endif

#include <cstdio>
#include <cinttypes>


#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <future>

//using namespace std::literals ;

#endif /* all_h */
