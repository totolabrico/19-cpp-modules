#include "Animal.hpp"

Animal::Animal(): _type("Cellule")
{
    std::cout << "Animal default constructor called" << std::endl;
};

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal name constructor called" << std::endl;
};

Animal::Animal(Animal const &src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
};

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
};

Animal &Animal::operator=(Animal const & src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if(this != &src)
        this->_type = src.getType();
    return *this;
}

std::string const &Animal::getType() const
{
    return _type;
}

void Animal::setType(std::string type)
{
    _type = type;
}

void Animal::makeSound()const
{
    std::cout << "a cellule does not make noise" << std::endl;
}