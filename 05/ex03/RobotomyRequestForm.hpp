#ifndef RRFForm_HPP
#define RRFForm_HPP

#include <iostream>
#include <fstream>
#include <stdbool.h>
#include "AForm.hpp"
#include "time.h"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
protected:
    virtual void concreteExecute()const;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(AForm const & src);
    virtual std::string const &getTarget()const;
    virtual ~RobotomyRequestForm();
};

#endif