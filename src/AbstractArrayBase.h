#pragma once

template <typename T>
class AbstractArrayBase
{
public:
    using iterator = T*;
    using const_iterator = const T*;

    virtual const_iterator cbegin() const = 0;
    virtual const_iterator begin() const = 0;
    virtual iterator begin() = 0;
    virtual const_iterator cend() const = 0;
    virtual const_iterator end() const = 0;
    virtual iterator end() = 0;
    virtual size_t size() const = 0;
    virtual ~AbstractArrayBase() = default;
};