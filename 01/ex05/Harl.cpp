#include "Harl.hpp"

Harl::Harl()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
    ptr[0] = &Harl::debug;
    ptr[1] = &Harl::info;
    ptr[2] = &Harl::warning;
    ptr[3] = &Harl::error;
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
    for (int i = 0; i < 4; i++)
    {
        if(!level.compare(levels[i]))
            (this->*ptr[i])();
    }
}