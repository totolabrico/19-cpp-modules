#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
T *copyArray(T *src, unsigned int len)
{
    T *res = new T[len];
    if(!res)
        return NULL;
    for (unsigned int i = 0; i < len; i++)
        res[i] = src[i];
    return (res);
}

template <typename T>
class Array
{
private:
    T *_content;
    unsigned int _size;
public:
    Array <T> (): _content(new T[0]), _size(0){};
    Array <T> (unsigned int n) : _content(new T[n]), _size(n){};
    Array <T> (Array const & src)
    {
        _content = copyArray(src.getContent(), src.size());
        _size = src.size();
    }
    Array &operator=(Array <T> const & src)
    {
        if(&src != this)
        {
            delete _content;
            _content = copyArray(src.getContent(), src.size());
            _size = src.size();         
        }
        return *this;
    }
    T &operator[](unsigned int n)
    {    
        if(n >= _size)
            throw std::out_of_range("Index is out of range");
        return _content[n];
    }
    ~Array <T>(){delete _content;};
    T *getContent() const {return _content;};
    unsigned int size() const {return _size;};
};

#endif