#include "Intern.hpp"

Intern::Intern()
{
    _form_names[0] = "shrubbery request";
    _form_names[1] = "robotomy request";
    _form_names[2] = "presidential request";
    _form_functions[0] = &Intern::newShrubberyForm;
    _form_functions[1] = &Intern::newRobotomyForm;
    _form_functions[2] = &Intern::newPresidentialForm;
}

Intern::~Intern(){};

AForm *Intern::newShrubberyForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::newRobotomyForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::newPresidentialForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *res;

    for (int i = 0; i < 3; i++)
    {
        if(!form.compare(_form_names[i]))
        {
            res = (this->*_form_functions[i])(target);
            std::cout << "Intern creates " << _form_names[i] << std::endl;
            return(res);
        }
    }
    std::cout << "Intern can not create Form, name does not exist " << std::endl;
    return(NULL);
}