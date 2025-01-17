#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    std::string const   _name;
    int                 _grade;
    void                checkGrade();
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat();
    Bureaucrat const &operator=(Bureaucrat const &src);
    std::string const &getName() const;
    int getGrade() const;
    void incGrade();
    void decGrade();
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

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &src);

#endif