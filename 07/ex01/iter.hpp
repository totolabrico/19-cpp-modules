#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

template<typename T>
void iter(T *addr, size_t len, void (*f)(T*))
{
    size_t i;

    if(!addr)
        return;
    i = 0;
    while(i < len)
    {
        f(&addr[i]);
        i++;
    }
}

template<typename T>
void add(T *addr)
{
    if(addr)
        *addr += 1;
}

template<typename T>
void print(T *addr)
{
    if(addr)
        std::cout << *addr << std::endl;
}

#endif