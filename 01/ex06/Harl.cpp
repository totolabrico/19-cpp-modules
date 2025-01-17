#include "Harl.hpp"

Harl::Harl(){
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
};

Harl::~Harl(){};

void Harl::debug( void )
{
    std::cout<< "il fait beau aujourd'hui" << std::endl;
}

void Harl::info( void )
{
    std::cout<< "il fait gris aujourd'hui" << std::endl;
}

void Harl::warning( void )
{
    std::cout<< "il pleut aujourd'hui" << std::endl;
}

void Harl::error( void )
{
    std::cout<< "ahalala quel temps de merde" << std::endl;
}

void Harl::complain(std::string level)
{
    int c;

    c = -1;
    for (int i = 0; i < 4; i++)
    {
        if(!level.compare(levels[i]))
            c = i;
    }
    switch (c)
    {
    case 0:
        debug();
        goto case1;
    case1:
    case 1:
        info();
        goto case2;
    case2:
    case 2:
        warning();
        goto case3;
    case3:
    case 3:
        error();
        break;
    default:
        std::cout << "Probably complaining about insignificant problems" << std::endl;
        break;
    }
}