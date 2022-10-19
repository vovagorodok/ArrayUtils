#pragma once
#include "AbstractArrayBase.h"
#include "MapPair.h"

template <typename Key, typename Value>
class AbstractMap : virtual public AbstractArrayBase<MapPair<Key, Value>>
{
public:
    using Base = AbstractArrayBase<MapPair<Key, Value>>;
    using iterator = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    virtual bool contains(const Key& key) const = 0;
    virtual const_iterator find(const Key& key) const = 0;
    virtual iterator find(const Key& key) = 0;
};