#ifndef SCFForm_HPP
#define SCFForm_HPP

#include <iostream>
#include <fstream>
#include <stdbool.h>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
protected:
    virtual void concreteExecute()const;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(AForm const & src);
    virtual std::string const &getTarget()const;
    virtual ~ShrubberyCreationForm();
};

#endif