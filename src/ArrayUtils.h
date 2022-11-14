#pragma once
#include <array>
#include <utility>

template<typename T, std::size_t N, typename Converter, typename... OtherT>
constexpr std::array<T, N> makeArray(Converter&& converter, OtherT&&... args)
{
    std::array<T, N> res{converter(args)...};
    return res; 
}

template<typename Key, typename Value, std::size_t N>
using ArrayOfPairs = std::array<std::pair<Key, Value>, N>;

template<typename Key, typename Value, std::size_t N>
constexpr ArrayOfPairs<Key, Value, N> makeArrayOfPairs(std::initializer_list<std::pair<Key, Value>> list)
{
    ArrayOfPairs<Key, Value, N> res;
    size_t pos = 0;
    for (const auto& el: list)
    {
        res[pos] = el;
        pos++;
    }
    return res; 
}

template<typename Key, typename Value, std::size_t N>
constexpr typename ArrayOfPairs<Key, Value, N>::iterator find(ArrayOfPairs<Key, Value, N>& arr, const Key& key)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
        if (it->first == key)
            return it;
    return arr.end();
}

template<typename Key, typename Value, std::size_t N>
constexpr typename ArrayOfPairs<Key, Value, N>::const_iterator find(const ArrayOfPairs<Key, Value, N>& arr, const Key& key)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
        if (it->first == key)
            return it;
    return arr.end();
}