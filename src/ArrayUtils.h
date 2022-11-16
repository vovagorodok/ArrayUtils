#pragma once
#include <array>
#include <utility>
#include <algorithm>

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
    std::copy(list.begin(), list.end(), res.begin());
    return res; 
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(PairArray<Key, Value, N>& arr, const Key& key)
{
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(const PairArray<Key, Value, N>& arr, const Key& key)
{
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}