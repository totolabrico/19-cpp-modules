#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name),_weapon(NULL){}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if(!this->_weapon)
        std::cout << this->_name << " has no weapon !" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}