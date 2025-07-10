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
    constexpr auto front() {
        return _arr[_head];
    }
    constexpr auto front() const {
        return _arr[_head];
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
            popSafeImpl();
    }
    template <typename... Args>
    constexpr bool emplace(Args&&... args) {
        if (full())
            return false;
        _arr[_tail] = T(std::forward<Args>(args)...);
        incrementTail();
        _size++;
        return true;
    }
    constexpr bool push(const T& value) {
        if (full())
            return false;
        _arr[_tail] = value;
        incrementTail();
        _size++;   
        return true;
    }
    constexpr bool push(T&& value) {
        if (full())
            return false;
        _arr[_tail] = std::move(value);
        incrementTail();
        _size++;
        return true;
    }
    constexpr bool pop() {
        if constexpr (std::is_trivially_destructible_v<T>) {
            return popFast();
        } else {
            return popSafe();
        }
    }
    constexpr bool popFast() {
        if (empty())
            return false;
        popFastImpl();
        return true;
    }
    constexpr bool popSafe() {
        if (empty())
            return false;
        popSafeImpl();
        return true;
    }
 
private:
    constexpr void popFastImpl() {
        incrementHead();
        _size--;
    }
    constexpr void popSafeImpl() {
        _arr[_head] = T{};
        popFastImpl();
    }
    constexpr void incrementHead() {
        _head++;
        if (_head == N)
            _head = 0;
    }
    constexpr void incrementTail() {
        _tail++;
        if (_tail == N)
            _tail = 0;
    }

    std::array<T, N> _arr;
    std::size_t _head;
    std::size_t _tail;
    std::size_t _size;
};