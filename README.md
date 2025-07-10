# Array Utils

Allows constexpr construction by:  
Function `makeArray()` to create array of types with complex constructions.  
Function `makePairArray()` to create mapped arrays.

Allows search:  
Functions `findByKey()`, `find()` to find pair in array using key.  
Function `findByValue()` to find pair in array using value.

Array based containers:  
Classes `SmallMap`, `SmallVector` and `SmallQueue`.

## Pair array advanteges
- Zero memory overhead and the same size as `std::array`
- Can be stored on static mamory or stack
- Linear search is ~3x faster than `std::maps` for small number of elements
- Doesn't require `operator<` or hash

Recommended to replace `std::map` when number of elements is less than 15.  
When number of elements is greater than 1000 `std::unordered_map` is recommended.  
More about tests in TESTS.md.

## Configuration
Library requires STL with c++17 or greater.  
For PlatformIO. Add to `platformio.ini`:
```
build_flags =
	-std=c++17
	-std=gnu++17
build_unflags =
	-std=gnu++11
```

For Arduino IDE. At boards package installation folder create `platform.local.txt`:
```
compiler.cpp.extra_flags=-std=c++17
```
