#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *res = new Zombie[N];
    if(!res)
        return(NULL);
    for (int i = 0; i< N; i++)
        res[i].set_name(name);
    return(res);
}