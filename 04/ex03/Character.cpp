#include "Character.hpp"

Character::Character()
{
    for (int i = 0 ; i < 4; i++)
        _inventory[i] = NULL;
    //std::cout << "Character default constructor called" << std::endl;
};

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0 ; i < 4; i++)
        _inventory[i] = NULL;
    //std::cout << "Character type constructor called" << std::endl;
};

Character::Character(Character const &src)
{
    for (int i = 0 ; i < 4; i++)
        _inventory[i] = NULL;
    *this = src;
    //std::cout << "Character copy constructor called" << std::endl;
};

Character::~Character()
{
    for (int i = 0 ; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
    //std::cout << "Character destructor called" << std::endl;
};

Character &Character::operator=(Character const & src)
{
    //std::cout << "Character copy assignment operator called" << std::endl;
    if(this == &src)
        return *this;
    _name = src.getName();
    for (int i = 0 ; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        _inventory[i] = src._inventory[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    if(!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            _inventory[i] = m;
            /*std::cout << "Character: " << _name
            << " equip " << _inventory[i]->getType()
            << " at index " << i << " in inventory"
            << std::endl;*/
            return;
        }
    }
    std::cout << "Character: " << _name
    << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    _inventory[idx] = NULL;
    std::cout << "Character :" << _name
    << " unequip inventory at index " << idx
    << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if(_inventory[idx])
        _inventory[idx]->use(target);
}
