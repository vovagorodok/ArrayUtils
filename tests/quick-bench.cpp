#include <iostream>
#include <utility>
#include <array>
#include <map>
#include <unordered_map>

const std::size_t size = 5;
const std::size_t repeats = 10000;

using PairArray = std::array<std::pair<int, int>, size>;
using StdMap = std::map<int, int>;
using StdUnoderedMap = std::unordered_map<int, int>;

void fillArray(PairArray& container)
{
  for (int i = 0; i < size; i++)
    container[i] = std::make_pair(i, i + 1);
}
template <typename ContainerT>
void fillMap(ContainerT& container)
{
  for (int i = 0; i < size; i++)
    container[i] = i + 1;
}

PairArray createPairArray()
{
  PairArray res;
  fillArray(res);
  return res;
}
StdMap createStdMap()
{
  StdMap res;
  fillMap(res);
  return res;
}
StdUnoderedMap createStdUnoderedMap()
{
  StdUnoderedMap res;
  fillMap(res);
  return res;
}

inline PairArray::const_iterator find(const PairArray& arr, int key)
{
  for (auto it = arr.begin(); it != arr.end(); it++)
    if (it->first == key)
      return it;
  return arr.end();
}

const auto pairArray = createPairArray();
const auto stdMap = createStdMap();
const auto stdUnoderedMap = createStdUnoderedMap();
int write = 0;


static void PairArrayFind(benchmark::State& state) 
{
  for (auto _ : state)
  {
    std::size_t times = repeats;
    while(times--)
    {
      write = find(pairArray, times % size)->second;
    }
  }
}
// Register the function as a benchmark
BENCHMARK(PairArrayFind);


static void StdMapFind(benchmark::State& state)
{
  for (auto _ : state) 
  {
    std::size_t times = repeats;
    while(times--)
    {
      write = stdMap.find(times % size)->second;
    }    
  }
}
// Register the function as a benchmark
BENCHMARK(StdMapFind);


static void StdUnoderedMapFind(benchmark::State& state)
{
  for (auto _ : state) 
  {
    std::size_t times = repeats;
    while(times--)
    {
      write = stdUnoderedMap.find(times % size)->second;
    }    
  }
}
// Register the function as a benchmark
BENCHMARK(StdUnoderedMapFind);