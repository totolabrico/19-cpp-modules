#include "PmergeMe.hpp"

unsigned int Jacobsthal(unsigned int aim)
{
    unsigned int a;

    a = 0;
    for (unsigned int i = 0; i < aim; i++)
        a = pow(2, i + 1) - a;
    return(a);
}