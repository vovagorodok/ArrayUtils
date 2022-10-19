#pragma once
#include "ConstructibleArray.h"
#include "AbstractArrayBase.h"

template <typename T, size_t N>
class VirtualSmallArrayBase : public ConstructibleArray<T, N>,
                              virtual public AbstractArrayBase<T>
{
public:
    using ConstructibleArray<T, N>::ConstructibleArray;
    using Base = AbstractArrayBase<T>;
    using iterator = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    const_iterator cbegin() const override
    {
        return array;
    }
    const_iterator begin() const override
    {
        return array;
    }
    iterator begin() override
    {
        return array;
    }
    const_iterator cend() const override
    {
        return array + N;
    }
    const_iterator end() const override
    {
        return array + N;
    }
    iterator end() override
    {
        return array + N;
    }
    size_t size() const override
    {
        return N;
    }

protected:
    T array[N];
};