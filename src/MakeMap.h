#pragma once
#include "SmallMap.h"

template<typename Key, typename Value, std::size_t N>
constexpr SmallMap<Key, Value, N> makeMap(std::initializer_list<typename SmallMap<Key, Value, N>::type> list)
{
    SmallMap<Key, Value, N> res;
    size_t pos = 0;
    for (const auto& el: list)
    {
        res.array[pos] = el;
        pos++;
    }
    return res; 
}