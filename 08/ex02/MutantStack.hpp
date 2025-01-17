#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
    MutantStack<T, C>(){}
    MutantStack<T, C>(MutantStack <T, C> const & src) : std::stack<T, C>(src)
    {
        *this = src;
    }
    MutantStack<T, C> &operator=(MutantStack <T, C> const & src)
    {
        if(this != &src)
            std::stack<T, C>::operator=(src);
        return *this;
    }
    ~MutantStack<T, C>(){}

    typedef typename C::iterator iterator;
    typedef typename C::const_iterator const_iterator;
    iterator begin(){return this->c.begin();};
    iterator end(){return this->c.end();};
    const_iterator begin() const {return this->c.begin();};
    const_iterator end() const {return this->c.end();};
};

#endif