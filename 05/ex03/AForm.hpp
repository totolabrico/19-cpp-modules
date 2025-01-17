#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdbool.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const   _name;
    bool                 _signed;
    int                 _sgrade;
    int                 _egrade;
    void                checkGrade();
protected:
    virtual void concreteExecute() const = 0;
public:
    AForm();
    AForm(std::string name, int sgrade, int egrade);
    AForm(AForm const &src);
    virtual ~AForm();
    AForm const &operator=(AForm const &src);
    std::string const &getName() const;
    bool getSigned() const;
    int getSgrade() const;
    int getEgrade() const;
    void beSigned(Bureaucrat const &b);
    void execute(Bureaucrat const & executor) const;
    virtual std::string const &getTarget()const = 0;

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
    class IsNotSignedException : public std::exception
    {
        public:
            virtual const char * what()const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, AForm const &src);

#endif