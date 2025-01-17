#include "Span.hpp"

Span::Span() : _size(0){};

Span::Span(unsigned int N) : _size(N){};

Span::Span(Span const & src)
{
    *this = src;
};

Span::~Span(){};

Span &Span::operator=(Span const & src)
{
    if(this != &src)
    {
        _content = src.getContent();
        _size = src.size();
    }
    return *this;   
}

std::vector <int> const & Span::getContent() const
{
    return _content;
}

unsigned int Span::size() const
{
    return _size;
}

void Span::addNumber(int value)
{
    if(_content.size() == _size)
        throw OutOfSizeException();
    _content.push_back(value);
}

void Span::addRange(int range[], unsigned int size)
{
    if(!range)
        return;
    if(_content.size() + size > _size)
        throw OutOfSizeException();
    _content.insert(_content.end(), range, range + size);
}

unsigned int Span::longestSpan() const
{
    if(_size < 2)
        throw ContainerTooSmallException();
    std::vector<int>::const_iterator min;
    std::vector<int>::const_iterator max;

    min = std::min_element(_content.begin(), _content.end());
    max = std::max_element(_content.begin(), _content.end());
    return(*max - *min);
}

unsigned int Span::shortestSpan() const
{
    int min, dif;

    if(_size < 2)
        throw ContainerTooSmallException();
    std::vector<int> cpy(_content.size());
    std::copy(_content.begin(), _content.end(), cpy.begin());
    std::sort(cpy.begin(), cpy.end());
    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator ite = cpy.end();
    min = INT_MAX;
    for (it = cpy.begin(); it < ite - 1; it++)
    {
        dif = *(it + 1) - *it ;
        if(dif < min)
            min = dif;
    }
    return(min);
}

const char *Span::OutOfSizeException::what() const throw()
{
    return("Span Out Of Size Exception");
}

const char *Span::ContainerTooSmallException::what() const throw()
{
    return("Span Too Small Exception");
}

void Span::print_content() const
{
    std::vector<int>::const_iterator it;
    std::vector<int>::const_iterator ite = _content.end();

    std::cout << "Span content : ";
    for(it = _content.begin(); it < ite; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}