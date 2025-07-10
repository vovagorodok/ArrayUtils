#pragma once
#include <array>

template<typename T, std::size_t N>
class SmallVector
{
public:
    constexpr SmallVector() :  _arr(), _size() {
    }
    template <typename... OtherT>
    constexpr SmallVector(OtherT&&... args) : _arr{args...}, _size(sizeof...(args)) {
    }
    constexpr std::size_t capacity() const {
        return N;
    }
    constexpr std::size_t available() const {
        return N - _size;
    }
    constexpr std::size_t size() const {
        return _size;
    }
    constexpr bool empty() const {
        return !_size;
    }
    constexpr bool full() const {
        return _size >= N;
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
    template <typename... Args>
    constexpr bool emplace(Args&&... args) {
        if (full())
            return false;
        _arr[_size++] = T(std::forward<Args>(args)...);
        return true;
    }
    constexpr bool push(const T& value) {
        if (full())
            return false;
        _arr[_size++] = value;
        return true;
    }
    constexpr bool push(T&& value) {
        if (full())
            return false;
        _arr[_size++] = std::move(value);
        return true;
    }
    template <std::size_t OtherN>
    constexpr bool push(const SmallVector<T, OtherN>& other) {
        return push(other._arr, other.size());
    }
    template <std::size_t OtherN>
    constexpr bool push(const std::array<T, OtherN>& arr) {
        return push(arr, arr.size());
    }
    template <typename OthTerT, std::size_t OtherN>
    friend class SmallVector;
 
private:
    template <std::size_t OtherN>
    constexpr bool push(const std::array<T, OtherN>& arr, std::size_t size) {
        if (_size + size > N)
            return false;
        for (std::size_t pos = 0; pos < size; pos++)
            _arr[_size + pos] = arr[pos];
        _size += size;
        return true;
    }

    std::array<T, N> _arr;
    std::size_t _size;
};