#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
protected:
    std::string _type;
public:
    Ice();
    Ice(AMateria const &src);
    virtual ~Ice();

    Ice &operator=(Ice const & rhs);

    void setType();
    virtual AMateria* clone()const;
    virtual void use(ICharacter& target);
};

#endif