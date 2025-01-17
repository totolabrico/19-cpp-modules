#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    AMateria *_inventory[4];
    std::string _name;
public:
    Character();
    Character(std::string const & name);
    Character(Character const &src);
    virtual ~Character();

    Character &operator=(Character const & rhs);
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif