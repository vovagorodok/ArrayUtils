#pragma once
#include "SmallArrayBase.h"

template <typename T, size_t N>
class SmallArray : public SmallArrayBase<T, N>
{
public:
    using SmallArrayBase<T, N>::SmallArrayBase;
    using reference = T&;
    using const_reference = const T&;

    constexpr const_reference operator[](size_t pos) const
    {
        return this->array[pos];
    }
    inline reference operator[](size_t pos)
    {
        return this->array[pos];
    }
    constexpr bool contains(const T& value) const
    {
        for (size_t pos = 0; pos < N; pos++)
            if (this->array[pos] == value)
                return true;
        return false;
    }
};