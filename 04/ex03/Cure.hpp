#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
protected:
    std::string _type;
public:
    Cure();
    Cure(AMateria const &src);
    virtual ~Cure();

    Cure &operator=(Cure const & rhs);

    void setType();
    virtual AMateria* clone()const;
    virtual void use(ICharacter& target);
};

#endif