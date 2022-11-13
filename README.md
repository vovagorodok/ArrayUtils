# Small Container Utils
 
Function `makeArray` to create array of complex types. \
Function `makeMap` to create `SmallMap` (array of pairs). \
Allows constexpr construction. \
Has all advanteges as `std::array`:
- Zero memory overhead and the same size as c array
- Can be stored on static mamory or stack

Requires STL and c++14