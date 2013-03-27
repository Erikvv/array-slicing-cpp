array-slicing-cpp
=================

Slicing for std::array's in C++

example #1
----------

'#include "slice.hpp"
#include <iostream>

using namespace std;

int main() {
   array<int,8> vals = { 10, 20, 30, 40, 50, 60, 70, 80 };

   // 2 is the index, 4 is the number of items
   array<int,4> subvals = slice<2,4>(vals);

   // prints "30 40 50 60"
   for( int v : subvals )
      cout<< v << " ";
}'

