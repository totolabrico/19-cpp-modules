#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", 145, 137),
    _target("default_target")
    {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : 
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
    {};

ShrubberyCreationForm::ShrubberyCreationForm(AForm const & src) : 
    AForm(src),
    _target(src.getTarget())
    {};

ShrubberyCreationForm::~ShrubberyCreationForm(){};


std::string const &ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::concreteExecute() const
{
    std::string tree =  "     _-_/\n"
                        "  /~~   ~~/\n"
                        "/~~         ~~/\n"
                        "{               }/\n"
                        "/  _-     -_  /\n"
                        "~     \\ //  ~/\n"
                        "_- -   | | _- _/\n"
                        "  _ -  | |   -_/\n"
                        "      // \\";
    std::ofstream stream;

    stream.open((_target + "_shrubbery").c_str());
    std::cout << getName() << " execute " << getTarget() << std::endl;
    stream << tree << std::endl;
    stream.close();
}
