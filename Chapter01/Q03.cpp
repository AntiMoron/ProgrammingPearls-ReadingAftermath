/*
* Author: AntiMoron
* briefs:
* Guru's Q 03: 运行时效率是设计目标的一个重要组成部分，所得到的程序需要足够搞笑。在你自己的系统上实现位图排序
* 并度量其运行时间。改时间与系统排序的运行时间以及Q01中排序的寻星时间相比如何？假设n为1e7，且输入文件包含1e6个整数。
*/

#include<iostream>
#include<chrono>
#include<random>
#include<array>
#define MAX_COUNT size_t(1e4)
#define NUMBER_COUNT size_t(1e3)
uint32_t bitmapArray[1 + (MAX_COUNT / sizeof(uint32_t) / 8)];

std::array<uint32_t, NUMBER_COUNT> generateInput() 
{
    int times = NUMBER_COUNT;
    std::array<uint32_t, NUMBER_COUNT> result;
    for(int i = 0; i < result.size(); i++)
    {
        result[i] = i * 10;
    }
    std::random_device rd;
	std::uniform_int_distribution<int> dist(0, NUMBER_COUNT);
    while(--times) 
    {
        size_t a = dist(rd);
        size_t b = dist(rd);
        std::swap(result[a], result[b]);
    }
    return std::move(result);
}

template<size_t size>
void changeBit(uint32_t (&arr)[size], size_t index, char value)
{
    const auto elementSize = sizeof(uint32_t) * 8;
    const auto elementIndex = index / elementSize;
    const auto bitIndex = (elementSize * 8) - (index % elementSize) - 1;
    if(value) 
    {
        const auto mask = uint32_t(1 << bitIndex);
        arr[elementIndex] |= mask;
    }
    else 
    {
        const auto mask = uint32_t(-1) ^ (1 << bitIndex);
        arr[elementIndex] &= mask;
    }
}

template<size_t size>
std::array<uint32_t, NUMBER_COUNT> generateBit(uint32_t (&arr)[size]) 
{
    std::array<uint32_t, NUMBER_COUNT> result;
    const auto bitsPer = sizeof(uint32_t) * 8;
    size_t cur = 0;
    for(size_t v = 0; v < size; v++)
    {
        for(int i = 0; i < bitsPer; i++) 
        {
            if(arr[v] >> (bitsPer - i - 1))
            {
                result[cur++] = v * bitsPer + i;
            }
        }
    }
    return std::move(result);
}


extern "C" int main() 
{
    auto input = generateInput();
    for(const auto x: input){
        std::cout << x << std::endl;
    }
    auto start = std::chrono::high_resolution_clock::now();
    for(const auto num: input) 
    {
        changeBit(bitmapArray, num, 1);
    }
    auto output = generateBit(bitmapArray);
    for(int i =0;i<10;i++) {
        std::cout << output[i] << " ";
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count();
    return 0;
}