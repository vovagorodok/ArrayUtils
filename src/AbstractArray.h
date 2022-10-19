#pragma once
#include "AbstractArrayBase.h"

template <typename T>
class AbstractArray : virtual public AbstractArrayBase<T>
{
public:
    using reference = T&;
    using const_reference = const T&;

    virtual const_reference operator[](size_t pos) const = 0;
    virtual reference operator[](size_t pos) = 0;
    virtual bool contains(const T& value) const = 0;
};