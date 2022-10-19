#pragma once
#include <initializer_list>

template <typename T, size_t N>
class SmallArrayBase
{
public:
    using iterator = T*;
    using const_iterator = const T*;

    constexpr SmallArrayBase() = default;
    constexpr SmallArrayBase(const SmallArrayBase& other) = default;
    constexpr SmallArrayBase(SmallArrayBase&& other) = default;
    constexpr SmallArrayBase(T&& arg) :
        array{arg}
    {}
    template<typename... Types>
    constexpr SmallArrayBase(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    template<typename Converter, typename OtherT, typename... OtherTypes>
    constexpr SmallArrayBase(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
        array{converter(arg), converter(args)...}
    {}
    inline SmallArrayBase(std::initializer_list<T> list) :
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
    inline SmallArrayBase(Converter&& converter, std::initializer_list<OtherT> list) :
        array{}
    {
        size_t pos = 0;
        for (const OtherT& el: list)
        {
            array[pos] = converter(el);
            pos++;
        }
    }
    inline SmallArrayBase& operator=(const SmallArrayBase& other) = default;
    inline SmallArrayBase& operator=(SmallArrayBase&& other) = default;

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

protected:
    T array[N];
};