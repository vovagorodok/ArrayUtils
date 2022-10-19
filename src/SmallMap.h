#pragma once
#include <initializer_list>

template <typename Key, typename Value, size_t N>
class SmallMap
{
public:
    template <typename K, typename V>
    struct Pair
    {
        K key;
        V value;
    };
    using T = Pair<Key, Value>;
    using iterator = T*;
    using const_iterator = const T*;

    constexpr SmallMap() = default;
    constexpr SmallMap(const SmallMap& other) = default;
    constexpr SmallMap(SmallMap&& other) = default;
    constexpr SmallMap(T&& arg) :
        array{arg}
    {}
    template<typename... Types>
    constexpr SmallMap(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    template<typename Converter, typename OtherT, typename... OtherTypes>
    constexpr SmallMap(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
        array{converter(arg), converter(args)...}
    {}
    inline SmallMap(std::initializer_list<T> list) :
        array{}
    {
        size_t pos = 0;
        for (const T& el: list)
        {
            array[pos] = el;
            pos++;
        }
    }
    template<typename Converter, typename OtherT>
    inline SmallMap(Converter&& converter, std::initializer_list<OtherT> list) :
        array{}
    {
        size_t pos = 0;
        for (const OtherT& el: list)
        {
            array[pos] = converter(el);
            pos++;
        }
    }
    inline SmallMap& operator=(const SmallMap& other) = default;
    inline SmallMap& operator=(SmallMap&& other) = default;

    constexpr const_iterator cbegin() const
    {
        return array;
    }
    constexpr const_iterator begin() const
    {
        return array;
    }
    inline iterator begin()
    {
        return array;
    }
    constexpr const_iterator cend() const
    {
        return array + N;
    }
    constexpr const_iterator end() const
    {
        return array + N;
    }
    inline iterator end()
    {
        return array + N;
    }
    constexpr size_t size() const
    {
        return N;
    }
    constexpr bool contains(const Key& key) const
    {
        return find(key) != cend();
    }
    constexpr const_iterator find(const Key& key) const
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos].key == key)
                return array + pos;
        return cend();
    }
    inline iterator find(const Key& key)
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos].key == key)
                return array + pos;
        return end();
    }

private:
    T array[N];
};