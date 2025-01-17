#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat toto("toto", 1);
    Intern intern;
    AForm *f;
    
    f = intern.makeForm("shrubbery request", "michel");
    if(f)
    {
        toto.signForm(*f);
        toto.executeForm(*f);
        delete f;
    }

    f = intern.makeForm("presidential request", "michel");
    if(f)
    {
        toto.signForm(*f);
        toto.executeForm(*f);
        delete f;
    }
    
    f = intern.makeForm("roboto", "michel");
    if(f)
    {
        toto.signForm(*f);
        toto.executeForm(*f);
        delete f;
    }

    return(0);
}