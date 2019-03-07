#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include "alg.h"
#include <algorithm>
#include <iterator>
#include "dinamichesky_Massive.h"
#include "vector.h"

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

/*void shell_sort1(int* arr, int size)
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
}*/

template <class Iter, class BO >
void shell_sort(Iter first, Iter last, BO op)
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
    dinamichesky_massive array1(5);
    dinamichesky_massive array2(5);
    stu::fill_random(array1.begin(), array1.end(), 0, 10);
    stu::fill_random(array2.begin(), array2.end(), 10, 20);
    print_contenier(array1.begin(), array1.end());
    std::cout<<std::endl;
    print_contenier(array2.begin(), array2.end());
    dinamichesky_massive array3;
    for (auto i = array1.begin(); i != array1.end(); ++i)
    {
        array3.push_back(*i);
    }
    for (auto i = array2.begin(); i != array2.end(); ++i)
    {
        array3.push_back(*i);
    }
    shell_sort(array3.begin(), array3.end(), [](int a, int b) {return a > b ;});
    std::cout<<std::endl;
    print_contenier(array3.begin(), array3.end());
    /*
    std::vector<int> rendvec(10);
    stu::fill_random(rendvec.begin(), rendvec.end(), 1, 20);
    //print_contenier(rendvec.begin(), rendvec.end());
    shell_sort2(rendvec.begin(), rendvec.end(), [](int value1,int value2){return value1 > value2;});
   // print_contenier(rendvec.begin(), rendvec.end());
    stu::simple_vector<int> a{1, 2, 5, 5};
    dinamichesky_massive b {1, 6, 1, 6, 5, 8, 5, 5, 54};
    for(auto i = a.begin(); i != a.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
   /* a.push_back(4);
    a.push_back(5);
    std::cout << b[1];
    //auto x = {1, 2, 3, 4, 5};*/


    return 0;
}
