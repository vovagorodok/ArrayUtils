#pragma once
#include <array>

template<typename T, std::size_t N>
class SmallVector
{
public:
    constexpr SmallVector() :  _arr{}, _size() {
    }
    template <typename... OtherT>
    constexpr SmallVector(OtherT&&... args) : _arr{args...}, _size(sizeof...(args)) {
    }
    constexpr std::size_t maxSize() const {
        return N;
    }
    constexpr std::size_t size() const {
        return _size;
    }
    constexpr bool empty() const {
        return !_size;
    }
    constexpr auto begin() {
        return _arr.begin();
    }
    constexpr auto begin() const {
        return _arr.begin();
    }
    constexpr auto cbegin() const {
        return _arr.cbegin();
    }
    constexpr auto end() {
        return _arr.begin() + _size;
    }
    constexpr auto end() const {
        return _arr.begin() + _size;
    }
    constexpr auto cend() const {
        return _arr.cbegin() + _size;
    }
    constexpr auto at(std::size_t pos) {
        return _arr.at(pos);
    }
    constexpr auto at(std::size_t pos) const {
        return _arr.at(pos);
    }
    constexpr auto operator[](std::size_t pos) {
        return _arr[pos];
    }
    constexpr auto operator[](std::size_t pos) const {
        return _arr[pos];
    }
    constexpr auto front() {
        return _arr.front();
    }
    constexpr auto front() const {
        return _arr.front();
    }
    constexpr void clear() {
        _size = 0;
    }
    constexpr bool add(const T& value) {
        if (_size >= N)
            return false;
        _arr[_size++] = value;
        return true;
    }
    template <std::size_t OtherN>
    constexpr bool add(const SmallVector<T, OtherN>& other) {
        if (_size + other.size() > N)
            return false;
        for (std::size_t pos = 0; pos < other.size(); pos++)
            _arr[_size + pos] = other[pos];
        _size += other.size();
        return true;
    }

private:
    std::array<T, N> _arr;
    std::size_t _size;
};