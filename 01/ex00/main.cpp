#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);


int main()
{
    Zombie *z;

    z = newZombie("toto");
    z->announce();
    randomChump("matmat");
    delete(z);
    return(0);
}