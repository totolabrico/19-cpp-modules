#include "AMateria.hpp"

AMateria::AMateria()
{
    //std::cout << "AMateria default constructor called" << std::endl;
};

AMateria::AMateria(std::string const &type) : _type(type)
{
    //std::cout << "AMateria type constructor called" << std::endl;
};

AMateria::AMateria(AMateria const &src)
{
    //std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
};

AMateria::~AMateria()
{
    //std::cout << "AMateria destructor called" << std::endl;
};

AMateria &AMateria::operator=(AMateria const & src)
{
    //std::cout << "AMateria copy assignment operator called" << std::endl;
    if(this != &src)
        _type = src.getType();
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::setType(std::string type)
{
    _type = type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << getType() << ": * AMateria use "
    << target.getName() << " *" << std::endl;
}
