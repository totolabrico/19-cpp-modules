#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
    AForm("PresidentialPardonForm", 25, 5),
    _target("default_target")
    {};

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : 
    AForm("PresidentialPardonForm", 25, 5),
    _target(target)
    {};

PresidentialPardonForm::PresidentialPardonForm(AForm const & src) : 
    AForm(src),
    _target(src.getTarget())
    {};

PresidentialPardonForm::~PresidentialPardonForm(){};


std::string const &PresidentialPardonForm::getTarget() const
{
    return (_target);
}

void PresidentialPardonForm::concreteExecute() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
