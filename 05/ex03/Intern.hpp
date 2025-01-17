#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        std::string _form_names[3];
        AForm *(Intern::*_form_functions[3])(std::string);
        AForm *newShrubberyForm(std::string target);
        AForm *newRobotomyForm(std::string target);
        AForm *newPresidentialForm(std::string target);

    public:
        Intern();
        ~Intern();
        AForm *makeForm(std::string form, std::string target);
};

#endif