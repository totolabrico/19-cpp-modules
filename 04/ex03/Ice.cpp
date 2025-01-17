#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    //std::cout << "Ice default constructor called" << std::endl;
};

Ice::Ice(AMateria const &src)
{
    //std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
};

Ice::~Ice()
{
    //std::cout << "Ice destructor called" << std::endl;
};

Ice &Ice::operator=(Ice const & src)
{
    //std::cout << "Ice copy assignment operator called" << std::endl;
    if(this != &src)
        _type = src.getType();
    return *this;
}

void Ice::setType()
{
    AMateria::setType("ice");
}

AMateria *Ice::clone()const
{
    return(new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
    << target.getName() << " *" << std::endl;
}
