# Array Utils

Allows constexpr construction by: \
Function `makeArray()` to create array of types with complex constructions. \
Function `makePairArray()` to create mapped arrays.

Allows search: \
Function `find()` to find pair in array using on key.

Array of pairs advanteges:
- Zero memory overhead and the same size as `std::array`
- Can be stored on static mamory or stack
- Linear search is ~3x faster than `std::maps` for small number of elements
- Doesn't require `operator<` or hash

Recommended to replace `std::map` when number of elements is less than 15. \
When number of elements is greater than 1000 `std::unordered_map` is recommended. \
More about tests in TESTS.md

Library requires STL and c++14 or greater.
