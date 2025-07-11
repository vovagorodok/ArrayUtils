#pragma once
#include <array>
#include <type_traits>

template<typename T, std::size_t N>
class SmallQueue
{
public:
    constexpr SmallQueue() :  _arr(), _head(), _tail(), _size() {
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
    constexpr void clear() {
        if constexpr (std::is_trivially_destructible_v<T>) {
            clearFast();
        } else {
            clearSafe();
        }
    }
    constexpr void clearFast() {
        _head = 0;
        _tail = 0;
        _size = 0;
    }
    constexpr void clearSafe() {
        while (!empty())
            popSafe();
    }
    template <typename... Args>
    constexpr bool emplace(Args&&... args) {
        if (full())
            return false;
        _arr[_tail] = T(std::forward<Args>(args)...);
        incrementSize();
        return true;
    }
    constexpr bool push(const T& value) {
        if (full())
            return false;
        _arr[_tail] = value;
        incrementSize();
        return true;
    }
    constexpr bool push(T&& value) {
        if (full())
            return false;
        _arr[_tail] = std::move(value);
        incrementSize();
        return true;
    }
    constexpr auto pop() {
        if constexpr (std::is_trivially_destructible_v<T>) {
            return popFast();
        } else {
            return popSafe();
        }
    }
    constexpr auto popFast() {
        auto head = _head;
        if (!empty()) {
            decrementSize();
        }
        return _arr[head];
    }
    constexpr auto popSafe() {
        auto value = std::move(_arr[_head]);
        if (!empty()) {
            _arr[_head] = T{};
            decrementSize();
        }
        return value;
    }
 
private:
    constexpr void decrementSize() {
        increment(_head);
        _size--;
    }
    constexpr void incrementSize() {
        increment(_tail);
        _size++;
    }
    constexpr void increment(std::size_t& index) {
        index++;
        if (index == N)
            index = 0;
    }

    std::array<T, N> _arr;
    std::size_t _head;
    std::size_t _tail;
    std::size_t _size;
};