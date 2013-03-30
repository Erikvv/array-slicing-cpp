array-slicing-cpp
=================

Slicing for std::array's in C++

advantages:
- no dynamic memory allocation
- no unnecessary copies
- safe

example #1 
----------
Both size and start index defined at compile-time.

    #include "slice.hpp"
    #include <iostream>

    using namespace std;

    int main() {
       array<int,8> vals = { 10, 20, 30, 40, 50, 60, 70, 80 };
 
       /*  2 is the starting index, 6 is the upper index.
        *  The upper index is an open interval, so vals[6] is not included.
        *  This line generates no instructions and does not copy data,
        *  It just tells the compiler how to interpret the bits.
        *  Does not compile if the new array exceeds the range of the old one. */
       auto& subvals = slice<2,6>(vals);   // type: array<int,4>&
 
         // prints "30 40 50 60"
       for( int v : subvals )
          cout<< v << " ";

         // this performs a copy (no '&' after auto)
         // computing array.size() at compiletime is not widely supported yet
       auto pizza = slice<2,subvals.size()>(subvals)    

         // prints "50 60"
       for( int w : pizza )
            cout<< w << " ";
    }

example #2
----------
Size defined at compile-time, but start index defined at runtime.

    #include "slice.hpp"
    #include <iostream>

    using namespace std;

    int main() {
        array<char,13> haystack = {"Hello world!"};
        array<char,5>  needle   = {'w','o','r','l','d'};
        
        int index;
        cin>> index;
        // afaik no other way to do this than with a copy 
        // (or pointer, but that is what we try to avoid)
        auto test = slice<5>(haystack,index);

        if( needle == test )
            cout<< "Needle present at index" << endl;
        else
            cout<< "It's not there..." << endl;
    }
