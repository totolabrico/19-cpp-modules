#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

void example_1()
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}

void example_2()
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.attack();
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}

int main()
{
    example_1();
    example_2();
    return(0);
}