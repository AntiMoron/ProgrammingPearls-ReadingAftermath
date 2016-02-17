/*
* Author: AntiMoron
* briefs:
* Guru's Q 01: 如果不缺内存，如何使用一个具有库的语言来实现一种排序算法以表示&排序集合
*/

// Yes master. 我有这么几种版本
#define ANSWER_VERSION 1

#if ANSWER_VERSION == 1
// C++ 版本
/// avg O(N·log(N))
#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> datas{2,3,1,4,5};

extern "C" int main() 
{
    std::sort(std::begin(datas),std::end(datas));
    for(const auto i: datas)
    {
    	std::cout << i << " ";
    }
    return 0;
}
#endif
#if ANSWER_VERSION == 2
/// ~~ O(nlog(n))
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
std::vector<int> datas{2,3,1,4,5};

extern "C" int main() 
{
    std::set<int> sorter(std::begin(datas), std::end(datas));
    for(const auto i: sorter) 
    {
        std::cout << i << " ";
    }
    return 0;     
}
#endif
#if ANSWER_VERSION == 3
/// <= O(n^2)
#include<iostream>
#include<algorithm>
#include<vector>
std::vector<int> datas{2,3,1,4,5};

extern "C" int main() 
{
    for(int i = 0; i < datas.size(); i++)
    {
        auto bgItor = std::begin(datas);
        std::nth_element(bgItor, bgItor + i, std::end(datas));
        std::cout << datas[i] << " ";
    }
    return 0;
}
#endif