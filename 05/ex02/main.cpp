#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat toto("toto", 1);
    AForm *f;

    std::cout << toto << std::endl;

    f = new ShrubberyCreationForm("test");
    if(!f)
        return(1);
    toto.signForm(*f);
    toto.executeForm(*f);
    delete f;

    f = new RobotomyRequestForm("test");
    if(!f)
        return(1);
    toto.signForm(*f);
    toto.executeForm(*f);
    delete f;

    f = new PresidentialPardonForm("test");
    if(!f)
        return(1);
    toto.signForm(*f);
    toto.executeForm(*f);
    delete f;

    return(0);
}