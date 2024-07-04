#pragma once
#include <array>
#include <utility>
#include <algorithm>

template<typename Key, typename Value, std::size_t N>
class SmallMap
{
public:
    constexpr SmallMap() : _arr() {
    }
    constexpr SmallMap(std::initializer_list<std::pair<Key, Value>> list) : _arr() {
        std::copy(list.begin(), list.end(), _arr.begin());
    }
    constexpr std::size_t size() const {
        return N;
    }
    constexpr auto begin() const {
        return _arr.begin();
    }
    constexpr auto cbegin() const {
        return _arr.cbegin();
    }
    constexpr auto end() const {
        return _arr.end();
    }
    constexpr auto cend() const {
        return _arr.cend();
    }
    constexpr auto find(const Key& key) {
        return std::find_if(_arr.begin(), _arr.end(), [&key](const auto& pair){ return pair.first == key; });
    }
    constexpr auto find(const Key& key) const {
        return std::find_if(_arr.begin(), _arr.end(), [&key](const auto& pair){ return pair.first == key; });
    }
    constexpr auto findKey(const Key& key) {
        return std::find_if(_arr.begin(), _arr.end(), [&key](const auto& pair){ return pair.first == key; });
    }
    constexpr auto findKey(const Key& key) const {
        return std::find_if(_arr.begin(), _arr.end(), [&key](const auto& pair){ return pair.first == key; });
    }
    constexpr auto findValue(const Value& value) {
        return std::find_if(_arr.begin(), _arr.end(), [&value](const auto& pair){ return pair.second == value; });
    }
    constexpr auto findValue(const Value& value) const {
        return std::find_if(_arr.begin(), _arr.end(), [&value](const auto& pair){ return pair.second == value; });
    }

private:
    std::array<std::pair<Key, Value>, N> _arr;
};