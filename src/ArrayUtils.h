#pragma once
#include <array>
#include <utility>

template<typename T, std::size_t N, typename Converter, typename... OtherT>
constexpr auto makeArray(Converter&& converter, OtherT&&... args)
{
    std::array<T, N> res{converter(args)...};
    return res; 
}

template<typename Key, typename Value, std::size_t N>
using PairArray = std::array<std::pair<Key, Value>, N>;

template<typename Key, typename Value, std::size_t N>
constexpr auto makePairArray(std::initializer_list<std::pair<Key, Value>> list)
{
    PairArray<Key, Value, N> res;
    size_t pos = 0;
    for (const auto& el: list)
    {
        res[pos] = el;
        pos++;
    }
    return res; 
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(PairArray<Key, Value, N>& arr, const Key& key)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
        if (it->first == key)
            return it;
    return arr.end();
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(const PairArray<Key, Value, N>& arr, const Key& key)
{
    for (auto it = arr.begin(); it != arr.end(); it++)
        if (it->first == key)
            return it;
    return arr.end();
}