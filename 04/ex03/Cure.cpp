#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    //std::cout << "Cure default constructor called" << std::endl;
};

Cure::Cure(AMateria const &src)
{
    //std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
};

Cure::~Cure()
{
    //std::cout << "Cure destructor called" << std::endl;
};

Cure &Cure::operator=(Cure const & src)
{
    //std::cout << "Cure copy assignment operator called" << std::endl;
    if(this != &src)
        _type = src.getType();
    return *this;
}

void Cure::setType()
{
    AMateria::setType("Cure");
}

AMateria *Cure::clone()const
{
    return(new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<< target.getName()
    << "'s wounds *" << std::endl;
}
