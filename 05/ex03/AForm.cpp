#include "AForm.hpp"

void AForm::checkGrade()
{
    if(_sgrade < 1 || _egrade < 1)
        throw GradeTooHighException();
    else if (_sgrade > 150 || _egrade > 150)
        throw GradeTooLowException();
}

AForm::AForm() : 
    _name("Default AForm"),
    _signed(false),
    _sgrade(150),
    _egrade(150)
{}

AForm::AForm(std::string name, int sgrade, int egrade) : 
    _name(name), 
    _signed(false),
    _sgrade(sgrade),
    _egrade(egrade)
{
    checkGrade();
}

AForm::AForm(AForm const &src) : 
    _name(src.getName()),
    _signed(src.getSigned()),
    _sgrade(src.getSgrade()),
    _egrade(src.getEgrade())
{}

AForm::~AForm(){};

AForm const &AForm::operator=(AForm const & src)
{
    if(this != &src)
    {
        _signed = src.getSigned();
        _sgrade = src.getSgrade();
        _egrade = src.getEgrade();
    }
    return(*this);
}

std::string const &AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return(_signed);
}

int AForm::getSgrade() const
{
    return(_sgrade);
}

int AForm::getEgrade() const
{
    return(_egrade);
}

void AForm::beSigned(Bureaucrat const &b)
{
    if(b.getGrade() > getSgrade())
        throw GradeTooHighException();
    else
        _signed = true;
}

void AForm::execute(Bureaucrat const &b)const
{
    if(!_signed)
        throw IsNotSignedException();
    else if(b.getGrade() > getEgrade())
        throw GradeTooHighException();
    else
        concreteExecute();
}

std::ostream &operator<<(std::ostream &stream, AForm const & src)
{
    stream << src.getName() 
    << ", is signed: " << src.getSigned()
    << ", signe grade: " << src.getSgrade()
    << ", execute grade: " << src.getEgrade() << ".";
    return (stream);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("AForm grade is too low");
}

const char *AForm::IsNotSignedException::what() const throw()
{
    return("AForm is not signed yet");
}