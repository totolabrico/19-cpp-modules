#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
};

Cat::Cat(Animal const &src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
};

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
};

Cat &Cat::operator=(Cat const & src)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if(this != &src)
    {
        Animal::setType(src.getType());
        delete(_brain);
        _brain = new Brain(*src.getBrain());
    }
    return *this;
}

void Cat::setType()
{
    Animal::setType("Cat");
}

void Cat::makeSound()const
{
    std::cout << "miaou" << std::endl;
}

Brain *Cat::getBrain()const
{
    return _brain;
}
