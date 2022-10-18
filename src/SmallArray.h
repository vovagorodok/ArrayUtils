#pragma once

template <typename T, size_t N>
class SmallArray
{
public:
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
    SmallArray& operator=(const SmallArray& other) = default;
    SmallArray& operator=(SmallArray&& other) = default;

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
    constexpr const T& operator[](size_t pos) const
    {
        return array[pos];
    }
    T& operator[](size_t pos)
    {
        return array[pos];
    }
    bool contains(const T& value) const
    {
        for (size_t pos = 0; pos < size(); pos++)
            if (array[pos] == value)
                return true;
        return false;
    }

private:
    T array[N];
};