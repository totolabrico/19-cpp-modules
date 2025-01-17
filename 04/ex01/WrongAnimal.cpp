#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Cellule")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal name constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
};

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & src)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if(this != &src)
        this->_type = src.getType();
    return *this;
}

std::string const &WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::setType(std::string type)
{
    _type = type;
}

void WrongAnimal::makeSound()const
{
    std::cout << "Wrong animal sound!" << std::endl;
}