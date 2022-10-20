#pragma once
#include <initializer_list>
#include <stddef.h>

template <typename T, size_t N>
class ConstructibleArray
{
public:
    constexpr ConstructibleArray() = default;
    constexpr ConstructibleArray(const ConstructibleArray& other) = default;
    constexpr ConstructibleArray(ConstructibleArray&& other) = default;
    constexpr ConstructibleArray(T&& arg) :
        array{arg}
    {}
    template<typename... Types>
    constexpr ConstructibleArray(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    template<typename Converter, typename OtherT, typename... OtherTypes>
    constexpr ConstructibleArray(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
        array{converter(arg), converter(args)...}
    {}
    inline ConstructibleArray(std::initializer_list<T> list) :
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
    inline ConstructibleArray(Converter&& converter, std::initializer_list<OtherT> list) :
        array{}
    {
        size_t pos = 0;
        for (const OtherT& el: list)
        {
            array[pos] = converter(el);
            pos++;
        }
    }
    inline ConstructibleArray& operator=(const ConstructibleArray& other) = default;
    inline ConstructibleArray& operator=(ConstructibleArray&& other) = default;

protected:
    T array[N];
};