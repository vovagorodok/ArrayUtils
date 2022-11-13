#pragma once
#include <array>

template<typename T, std::size_t N, typename Converter, typename... OtherT>
constexpr std::array<T, N> makeArray(Converter&& converter, OtherT&&... args)
{
    std::array<T, N> res{converter(args)...};
    return res; 
}