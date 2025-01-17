#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade()
{
    if(_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : 
    _name("Bobby Caldwell"),
    _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : 
    _name(name), _grade(grade)
{
    checkGrade();
}

Bureaucrat::Bureaucrat(std::string name) : 
    _name(name),
    _grade(150)
{}

Bureaucrat::Bureaucrat(int grade) : 
    _name("Jimmy Foster"),
    _grade(grade)
{
    checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : 
    _name(src.getName()),
    _grade(src.getGrade())
{}

Bureaucrat::~Bureaucrat(){};

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const & src)
{
    if(this != &src)
        _grade = src.getGrade();
    return(*this);
}

std::string const &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const & src)
{
    stream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (stream);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("bureaucrat grade is too low");
}

void Bureaucrat::incGrade()
{
    if(_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decGrade()
{
    if(_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << f.getName()
        << " because " << e.what() << std::endl;
    }   
}