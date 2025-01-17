#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
};

WrongCat::WrongCat(WrongAnimal const &src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
};

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat &WrongCat::operator=(WrongCat const & src)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if(this != &src)
        WrongAnimal::setType(src.getType());
    return *this;
}

void WrongCat::setType()
{
    WrongAnimal::setType("WrongCat");
}

void WrongCat::makeSound()const
{
    std::cout << "Wrong cat sound!" << std::endl;
}