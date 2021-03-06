#include <array>

template<size_t START, size_t END, class T, size_t ORIG>
std::array<T,END-START>& slice( std::array<T,ORIG>& arr) {
   static_assert( END <= ORIG
               && START < ORIG, 
               "slice(array): array index out of bounds");

   return *reinterpret_cast<std::array<T,END-START>*>(&arr[START]);
}


template<size_t LEN, class T, size_t ORIG>
std::array<T,LEN> slice( std::array<T,ORIG> arr, size_t start) {

    if( start + LEN >= ORIG )
        throw std::range_error("slice: array index out of bounds");
    if( start < 0 )
        throw std::range_error("slice: array index out of bounds");

    return *reinterpret_cast<std::array<T,LEN>*>(&arr[start]);
}
