/*
* Author: AntiMoron
* briefs:
* Guru's Q 02: 如何使用位逻辑运算（与、或、移位）实现位向量
*/

#include<iostream>
#include<bitset>
template<size_t size>
void changeBit(uint32_t (&arr)[size], size_t index, char value)
{
    const auto elementSize = sizeof(uint32_t);
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
void outputBinaryCode(uint32_t (&arr)[size])
{
    for(const auto num: arr)
        std::cout << std::move(std::bitset<8 * sizeof(uint32_t)>(num));
    std::cout << std::endl;
}



extern "C" int main() 
{
    uint32_t array[] = {0xff,0xff,0xff};
    changeBit(array, 2, 1);
    changeBit(array, 3, 1);
    outputBinaryCode(array);
    return 0;
}