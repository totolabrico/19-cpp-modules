#ifndef PPFForm_HPP
#define PPFForm_HPP

#include <iostream>
#include <fstream>
#include <stdbool.h>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
protected:
    virtual void concreteExecute()const;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(AForm const & src);
    virtual std::string const &getTarget()const;
    virtual ~PresidentialPardonForm();
};

#endif