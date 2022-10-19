#pragma once
#include "ConstructibleArray.h"

template <typename T, size_t N>
class SmallArrayBase : public ConstructibleArray<T, N>
{
public:
    using ConstructibleArray<T, N>::ConstructibleArray;
    using iterator = T*;
    using const_iterator = const T*;

    constexpr const_iterator cbegin() const
    {
        return this->array;
    }
    constexpr const_iterator begin() const
    {
        return this->array;
    }
    inline iterator begin()
    {
        return this->array;
    }
    constexpr const_iterator cend() const
    {
        return this->array + N;
    }
    constexpr const_iterator end() const
    {
        return this->array + N;
    }
    inline iterator end()
    {
        return this->array + N;
    }
    constexpr size_t size() const
    {
        return N;
    }
};