#pragma once
#include <initializer_list>

template <typename T, size_t N>
class SmallArray
{
public:
    using iterator = T*;
    using const_iterator = const T*;

    constexpr SmallArray() = default;
    constexpr SmallArray(const SmallArray& other) = default;
    constexpr SmallArray(SmallArray&& other) = default;
    constexpr SmallArray(T&& arg) :
        array{arg}
    {}
    template<typename... Types>
    constexpr SmallArray(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    template<typename Converter, typename OtherT, typename... OtherTypes>
    constexpr SmallArray(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
        array{converter(arg), converter(args)...}
    {}
    inline SmallArray(std::initializer_list<T> list) :
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
    inline SmallArray(Converter&& converter, std::initializer_list<OtherT> list) :
        array{}
    {
        size_t pos = 0;
        for (const OtherT& el: list)
        {
            array[pos] = converter(el);
            pos++;
        }
    }
    inline SmallArray& operator=(const SmallArray& other) = default;
    inline SmallArray& operator=(SmallArray&& other) = default;

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
    constexpr const T& operator[](size_t pos) const
    {
        return array[pos];
    }
    inline T& operator[](size_t pos)
    {
        return array[pos];
    }
    constexpr bool contains(const T& value) const
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos] == value)
                return true;
        return false;
    }

private:
    T array[N];
};