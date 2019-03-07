#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <initializer_list>
#include <iostream>
#include <algorithm>

namespace stu
{
 template <class T>
 struct simple_vector
 {
    using value_type = T;
    using pointer = T*;
    using size_type = unsigned int;
    using reference = T&;

    private:
    pointer storage;
    size_type m_size;
    size_type m_capasity;

    public:
    simple_vector () : m_size(0), m_capasity(10), storage(new value_type[m_capasity]){}
    simple_vector (size_type size)
    {
        m_capasity =  size;
        m_size = size;
        storage = new value_type[m_capasity];
    }
    simple_vector(std::initializer_list<value_type> l) : simple_vector()
    {
        for(auto i = l.begin(); i != l.end(); ++i)
        {
            push_back(*i);
        }
    }
    void m_reallocate ()
    {
        pointer temp = new value_type[m_capasity];
        std::copy(storage, storage + m_size, temp);
        delete[] storage;
        storage = temp;
    }
    reference operator[] (size_type index)
    {
        return storage[index];
    }
    void push_back (value_type value)
    {
        if(m_size == m_capasity)
        {
            m_capasity *= 2;
            m_reallocate();
        }
        storage[m_size++] = value;
    }
    void pop_back()
    {
        if(m_size != 0)
        {
            --m_size;
        }
    }
    pointer begin()
    {
        return storage;
    }
    pointer end()
    {
        return storage + m_size;
    }


 };
}

#endif // VECTOR_H_INCLUDED
