#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <climits>

class Span
{
private:
    unsigned int _size;
    std::vector <int> _content;
public:
    Span();
    Span(unsigned int N);
    Span(Span const & src);
    ~Span();
    Span &operator=(Span const & src);
    std::vector <int> const & getContent() const;
    unsigned int size()const;
    void addNumber(int value);
    void addRange(int range[], unsigned int size);
    unsigned int longestSpan() const;
    unsigned int shortestSpan() const;
    void print_content()const;
    class OutOfSizeException : public std::exception
    {
        virtual const char *what()const throw();
    };
   class ContainerTooSmallException : public std::exception
    {
        virtual const char *what()const throw();
    };
};

#endif