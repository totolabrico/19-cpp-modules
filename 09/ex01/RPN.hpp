#ifndef RPN_HPP
#define RPN_HPP

#include <vector>
#include <iostream>
#include <sstream>
class RPN
{
    private:
        std::string _str;
        bool isOperator(char c);
        int doOp(std::vector <int> & lst, char c);
    public:
        RPN();
        RPN(std::string str);
        RPN(RPN const & src);
        ~RPN();
        RPN &operator=(RPN const & src);
        int compute();
        class BadValueExeption : public std::exception
        {
            virtual char const *what() const throw();
        };
};

#endif