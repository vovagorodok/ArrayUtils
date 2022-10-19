#pragma once
#include "VirtualSmallArrayBase.h"
#include "AbstractMap.h"

template <typename Key, typename Value, size_t N>
class VirtualSmallMap : public VirtualSmallArrayBase<MapPair<Key, Value>, N>,
                        public AbstractMap<Key, Value>
{
public:
    using VirtualSmallArrayBase<MapPair<Key, Value>, N>::VirtualSmallArrayBase;
    using Base = AbstractMap<Key, Value>;
    using iterator = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    bool contains(const Key& key) const override
    {
        return find(key) != this->cend();
    }
    const_iterator find(const Key& key) const override
    {
        for (size_t pos = 0; pos < N; pos++)
            if (this->array[pos].key == key)
                return this->array + pos;
        return this->cend();
    }
    iterator find(const Key& key) override
    {
        for (size_t pos = 0; pos < N; pos++)
            if (this->array[pos].key == key)
                return this->array + pos;
        return this->end();
    }
};