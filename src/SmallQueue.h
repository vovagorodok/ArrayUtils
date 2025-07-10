#pragma once
#include <array>

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
        while (!empty())
            popImpl();
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
        if (empty())
            return false;
        popImpl();
        return true;
    }
 
private:
    constexpr void popImpl() {
        _arr[_head] = T{};
        incrementHead();
        _size--;
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