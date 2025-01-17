#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();

};

Dog::Dog(Animal const &src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
};

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
};

Dog &Dog::operator=(Dog const & src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if(this != &src)
    {
        Animal::setType(src.getType());
        delete(_brain);
        _brain = new Brain(*src.getBrain());
    }
    return *this;
}

void Dog::setType()
{
    Animal::setType("Dog");
}

void Dog::makeSound()const
{
    std::cout << "waf" << std::endl;
}

Brain *Dog::getBrain()const
{
    return _brain;
}
