#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
};

Brain::Brain(std::string const ideas[100])
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = ideas[i];
    std::cout << "Brain default constructor called" << std::endl;
};


Brain::Brain(Brain const &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
};

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
};

Brain &Brain::operator=(Brain const & src)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if(this != &src)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = src.getIdea(i);
    }
    return *this;
}

std::string Brain::getIdea(unsigned int id) const
{
    if(id >= 100)
        return NULL;
    return(_ideas[id]);
}