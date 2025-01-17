#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdbool.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const   _name;
    bool                 _signed;
    int                 _sgrade;
    int                 _egrade;
    void                checkGrade();
public:
    Form();
    Form(std::string name, int sgrade, int egrade);
    Form(Form const &src);
    ~Form();
    Form const &operator=(Form const &src);
    std::string const &getName() const;
    bool getSigned() const;
    int getSgrade() const;
    int getEgrade() const;
    void beSigned(Bureaucrat &b);
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what()const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what()const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, Form const &src);

#endif