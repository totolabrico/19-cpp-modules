#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bobby;

    bobby = NULL;
    try
    {
        bobby = new Bureaucrat("bobby", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    if (bobby)
    {
        std::cout << *bobby << std::endl;
        delete bobby;
    }

    bobby = NULL;
    try
    {
        bobby = new Bureaucrat("bobby", 1);
        bobby->incGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    if(bobby)
    {
        std::cout << *bobby << std::endl;
        delete bobby;
    }

    bobby = NULL;
    try
    {
        bobby = new Bureaucrat("bobby", 150);
        bobby->decGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    if(bobby)
    {
        std::cout << *bobby << std::endl;
        delete bobby;
    }
    return(0);
}