#pragma once

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
    constexpr SmallMap() = default;
    constexpr SmallMap(const SmallMap& other) = default;
    constexpr SmallMap(SmallMap&& other) = default;
    constexpr SmallMap(T&& arg) :
        array{arg}
    {}
    // template<typename... Types>
    // constexpr SmallMap(const T& arg0, const T& arg1, const Types&... args) :
    //     array{arg0, arg1, args...}
    // {}
    template<typename... Types>
    constexpr SmallMap(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    // template<typename Converter, typename OtherT, typename... OtherTypes>
    // constexpr SmallMap(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
    //     array{converter(arg), converter(args)...}
    // {}
    SmallMap& operator=(const SmallMap& other) = default;
    SmallMap& operator=(SmallMap&& other) = default;

    constexpr T* cbegin() const
    {
        return array;
    }
    constexpr T* begin() const
    {
        return array;
    }
    T* begin()
    {
        return array;
    }
    constexpr T* cend() const
    {
        return array + N;
    }
    constexpr T* end() const
    {
        return array + N;
    }
    T* end()
    {
        return array + N;
    }
    constexpr size_t size() const
    {
        return N;
    }
    bool contains(const Key& key) const
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos].key == key)
                return true;
        return false;
    }
    const T* find(const Key& key) const
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos].key == key)
                return array[pos];
        return cend();
    }
    T* find(const Key& key)
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos].key == key)
                return array[pos];
        return end();
    }

private:
    T array[N];
};