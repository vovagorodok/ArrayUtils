#pragma once
#include "SmallArrayBase.h"
#include "MapPair.h"

template <typename Key, typename Value, size_t N>
class SmallMap : public SmallArrayBase<MapPair<Key, Value>, N>
{
public:
    using SmallArrayBase<MapPair<Key, Value>, N>::SmallArrayBase;
    using Base = SmallArrayBase<MapPair<Key, Value>, N>;
    using iterator = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    constexpr bool contains(const Key& key) const
    {
        return find(key) != this->cend();
    }
    constexpr const_iterator find(const Key& key) const
    {
        for (size_t pos = 0; pos < this->size(); pos++)
            if (this->array[pos].key == key)
                return this->array + pos;
        return this->cend();
    }
    inline iterator find(const Key& key)
    {
        for (size_t pos = 0; pos < this->size(); pos++)
            if (this->array[pos].key == key)
                return this->array + pos;
        return this->end();
    }
};