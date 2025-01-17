#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
private:
    std::string const _name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce( void );
};



#endif