#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : 
    _name("claptrap"),
    _hit(10),
    _energy(10),
    _attack(0)
{
    std::cout << _name << ": default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hit(10),
    _energy(10),
    _attack(0)
 {
    std::cout << _name << ": name constructor" << std::endl;
 }

ClapTrap::ClapTrap(ClapTrap const &src) :
    _name(src.getName()),
    _hit(src.getHit()),
    _energy(src.getEnergy()),
    _attack(src.getAttack())
{
    std::cout << _name << ": copy constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << ": is dead" << std::endl;
}

std::string ClapTrap::getName() const
{
    return(_name);
}

unsigned int ClapTrap::getHit() const
{
    return(_hit);
}

unsigned int ClapTrap::getEnergy() const
{
    return(_energy);
}

unsigned int ClapTrap::getAttack() const
{
    return(_attack);
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_energy == 0)
        return;
    _hit += amount;
    _energy--;
}