#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("RobotomyRequestForm", 72, 45),
    _target("default_target")
    {
        srand (time(NULL));
    };

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : 
    AForm("RobotomyRequestForm", 72, 45),
    _target(target)
    {
        srand (time(NULL));
    };

RobotomyRequestForm::RobotomyRequestForm(AForm const & src) : 
    AForm(src),
    _target(src.getTarget())
    {
        srand (time(NULL));
    };

RobotomyRequestForm::~RobotomyRequestForm(){};


std::string const &RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::concreteExecute() const
{
    int coin;

    coin = rand() % 2;

    std::cout << " *drilling noises* ";
    if(coin)
        std::cout << getTarget() << ": has been robotomized." << std::endl;
    else
        std::cout << getTarget() << ": robotomy failed." << std::endl;
}
