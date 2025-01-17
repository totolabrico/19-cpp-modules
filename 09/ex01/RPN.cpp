#include "RPN.hpp"


RPN::RPN() : _str(""){}

RPN::RPN(std::string str) : _str(str){}

RPN::RPN(RPN const & src)
{
    *this = src;
}

RPN::~RPN(){};

RPN &RPN::operator=(RPN const & src)
{
    if( this != &src)
        _str = src._str;
    return *this;
}

char const *RPN::BadValueExeption::what()const throw()
{
    return("Error");
}

bool RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' )
        return (true);
    return(false);
}

int RPN::doOp(std::vector<int> & lst, char op)
{
    int a, b;

    if(lst.size() < 2)
        throw BadValueExeption();
    b = lst.back();
    lst.pop_back();
    a = lst.back();
    lst.pop_back();
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return(0);
}


int RPN::compute()
{
    char c;
    std::string dest;
    std::stringstream stream(_str);
    std::vector <int> values;

    while(getline(stream, dest, ' '))
    {
        if(dest.size() != 1)
            throw BadValueExeption();
        c = dest[0];
        if(c >= '0' && c <= '9')
            values.push_back(static_cast<int>(c - '0'));
        else if (isOperator(c))
            values.push_back(doOp(values, c));
        else
            throw BadValueExeption();
    }
    if(values.size() != 1)
        throw BadValueExeption();
    return(values.front());
}