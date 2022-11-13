#pragma once
#include <array>
#include <utility>

template <typename Key, typename Value, size_t N>
struct SmallMap
{
    using type = std::pair<Key, Value>;
    using iterator = typename std::array<type, N>::iterator;
    using const_iterator = typename std::array<type, N>::const_iterator;

    constexpr bool contains(const Key& key) const
    {
        return find(key) != this->cend();
    }
    constexpr const_iterator find(const Key& key) const
    {
        for (auto it = cbegin(); it != cend(); it ++)
            if (it->first == key)
                return it;
        return cend();
    }
    inline iterator find(const Key& key)
    {
        for (auto it = begin(); it != end(); it ++)
            if (it->first == key)
                return it;
        return end();
    }
    constexpr const_iterator cbegin() const
    {
        return array.cbegin();
    }
    constexpr const_iterator begin() const
    {
        return array.begin();
    }
    inline iterator begin()
    {
        return array.begin();
    }
    constexpr const_iterator cend() const
    {
        return array.cend();
    }
    constexpr const_iterator end() const
    {
        return array.end();
    }
    inline iterator end()
    {
        return array.end();
    }
    constexpr size_t size() const
    {
        return array.size();
    }

    std::array<type, N> array;
};