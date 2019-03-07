#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include "alg.h"
#include <algorithm>
#include <iterator>

template <class Iter, class BP >
void insert_sort(Iter first, Iter last, BP p)
{
    for(Iter i = first + 1; i != last; ++i)
    {
        for(Iter j = i; j != first && p(*j, *(j - 1)); --j)
        {
            std::iter_swap(j, j - 1);
        }
    }
}

void shell_sort1(int* arr, int size)
{
    for(int k = size / 2; k > 0; k /= 2)
    {
        for(int i = k; i != size; ++i)
        {
            for(int j = i; j > 0 && arr[j] < arr[j - k]; --j)
            {
                std::swap(arr[j], arr[j - k]);
            }
        }
    }
}

template <class Iter, class BO >
void shell_sort2(Iter first, Iter last, BO op)
{
    auto size = std::distance(first, last);
    for(int k = size / 2; k > 0; k /= 2)
    {
        for(Iter i = first + k; i != last; ++i)
        {
            for(Iter j = i; j > first && op(*j, *(j - k)); --j)
            {
                std::iter_swap(j, j - k);
            }
        }
    }
}

int main()
{

    std::vector<int> rendvec(10);
    stu::fill_random(rendvec.begin(), rendvec.end(), 1, 20);
    //print_contenier(rendvec.begin(), rendvec.end());
    shell_sort2(rendvec.begin(), rendvec.end(), [](int value1,int value2){return value1 > value2;});
    print_contenier(rendvec.begin(), rendvec.end());

    return 0;
}
