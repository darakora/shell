#ifndef ALG_H_INCLUDED
#define ALG_H_INCLUDED
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

#define print_contenier(first, last) std::for_each (first, last, [](int value) {std::cout << value << " ";});

namespace stu
{
template <class Iter, class Generator>
void generate (Iter first, Iter last, Generator g)
{
    for(; first != last; ++first)
    {
        *first = g();
    }
}
template <class Iter>
void fill_random(Iter first, Iter last, int min_el, int max_el)
{
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long int> uid(min_el, max_el);
    stu::generate(first, last, [&uid, &gen]()
    {
        return uid(gen);
    });

}
}

#endif // ALG_H_INCLUDED
