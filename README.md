array-slicing-cpp
=================

Slicing for std::array's in C++

advantages:
- no dynamic memory allocation
- no copies
- safe

example #1 
----------
Both size and start index defined at compile-time.

    #include "slice.hpp"
    #include <iostream>

    using namespace std;

    int main() {
       array<int,8> vals = { 10, 20, 30, 40, 50, 60, 70, 80 };
 
       // 2 is the starting index, 4 is the number of items
       // this line generates no instructions and does not copy data
       // It just tells the compiler how to interpret the bits
       array<int,4> subvals = slice<2,4>(vals);
 
       // prints "30 40 50 60"
       for( int v : subvals )
          cout<< v << " ";
    }

example #2
----------
Size defined at compile-time, but start index defined at runtime.
