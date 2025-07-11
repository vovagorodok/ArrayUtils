#pragma once
#include <array>
#include <utility>
#include <algorithm>

template<typename... OtherT>
constexpr auto countSize(OtherT... args) {
    return sizeof...(args);
}

template<typename T, std::size_t N, typename Converter, typename... OtherT>
constexpr auto makeArray(Converter&& converter, OtherT&&... args) {
    static_assert(N == sizeof...(args));
    std::array<T, N> res{converter(args)...};
    return res;
}

template<typename Key, typename Value, std::size_t N>
using PairArray = std::array<std::pair<Key, Value>, N>;

template<typename Key, typename Value, std::size_t N>
constexpr auto makePairArray(std::initializer_list<std::pair<Key, Value>> list) {
    PairArray<Key, Value, N> res;
    std::copy(list.begin(), list.end(), res.begin());
    return res;
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(PairArray<Key, Value, N>& arr, const Key& key) {
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto find(const PairArray<Key, Value, N>& arr, const Key& key) {
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto findByKey(PairArray<Key, Value, N>& arr, const Key& key) {
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto findByKey(const PairArray<Key, Value, N>& arr, const Key& key) {
    return std::find_if(arr.begin(), arr.end(), [&key](const auto& pair){ return pair.first == key; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto findByValue(PairArray<Key, Value, N>& arr, const Value& value) {
    return std::find_if(arr.begin(), arr.end(), [&value](const auto& pair){ return pair.second == value; });
}

template<typename Key, typename Value, std::size_t N>
constexpr auto findByValue(const PairArray<Key, Value, N>& arr, const Value& value) {
    return std::find_if(arr.begin(), arr.end(), [&value](const auto& pair){ return pair.second == value; });
}