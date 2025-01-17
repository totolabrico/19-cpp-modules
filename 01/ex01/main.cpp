#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *horde;
    
    horde = zombieHorde(10, "brian");
    if(!horde)
        return(1);
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    delete[] horde;
    return(0);
}