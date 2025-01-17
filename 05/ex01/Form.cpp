#include "Form.hpp"

void Form::checkGrade()
{
    if(_sgrade < 1 || _egrade < 1)
        throw GradeTooHighException();
    else if (_sgrade > 150 || _egrade > 150)
        throw GradeTooLowException();
}

Form::Form() : 
    _name("Default Form"),
    _signed(false),
    _sgrade(150),
    _egrade(150)
{}

Form::Form(std::string name, int sgrade, int egrade) : 
    _name(name), 
    _signed(false),
    _sgrade(sgrade),
    _egrade(egrade)
{
    checkGrade();
}

Form::Form(Form const &src) : 
    _name(src.getName()),
    _signed(src.getSigned()),
    _sgrade(src.getSgrade()),
    _egrade(src.getEgrade())
{}

Form::~Form(){};

Form const &Form::operator=(Form const & src)
{
    if(this != &src)
    {
        _signed = src.getSigned();
        _sgrade = src.getSgrade();
        _egrade = src.getEgrade();
    }
    return(*this);
}

std::string const &Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return(_signed);
}

int Form::getSgrade() const
{
    return(_sgrade);
}

int Form::getEgrade() const
{
    return(_egrade);
}

void Form::beSigned(Bureaucrat &b)
{
    if(b.getGrade() > getSgrade())
        throw GradeTooHighException();
    else
        _signed = true;
}

std::ostream &operator<<(std::ostream &stream, Form const & src)
{
    stream << src.getName() 
    << ", is signed: " << src.getSigned()
    << ", signe grade: " << src.getSgrade()
    << ", execute grade: " << src.getEgrade() << ".";
    return (stream);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("Form grade is too low");
}