#include "ScalarConverter.hpp"

char ScalarConverter::getType(std::string str)
{
    std::istringstream iss(str);
    int i;
    float f;
    double d;

    if(str.length() == 0)
        return(0);
    if (str.length() == 1 && !isdigit(str[0]))
        return('c');
    iss >> i;
    if (!iss.fail() && iss.eof())
        return('i');
    if(str[str.length() - 1] == 'f')
    {
        str = str.substr(0, str.length() - 1);
        std::istringstream iss2(str);
        iss2 >> f;
        if (!iss2.fail() && iss2.eof())
            return('f');
        return(0);
    }
    iss.clear();
    iss.seekg(0);
    iss >> d;
    if(iss.eof())
        return('d');
    return (0);
    }

int ScalarConverter::getInt(std::string str)
{
    int res;
    std::istringstream iss(str);

    iss >> res;
    return res;
}

float ScalarConverter::getFloat(std::string str)
{
    float res;
    std::stringstream iss(str);

    iss >> res;
    return res;
}

long double ScalarConverter::getDouble(std::string str)
{
    long double res;
    std::stringstream iss(str);

    iss >> res;
    return res;
}

void ScalarConverter::printChar(char type, std::string str)
{
    char c;
    std::cout << "char: ";
    if(type == 'c')
        std::cout << str[0] << std::endl;
    else if (type == 'i')
    {
        int i = ScalarConverter::getInt(str);
        if(i >= static_cast <int> (std::numeric_limits<char>::min())
            && i <= static_cast <int> (std::numeric_limits<char>::max()))
        {
            c = static_cast <char> (i);
            if(isprint(c))
                std::cout << c << std::endl;
            else
                std::cout << "Not Displayable" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void ScalarConverter::printInt(char type, std::string str)
{
    std::cout << "int: ";
    if(!type || type == 'c')
        std::cout << "impossible";
    else if (type == 'i')
        std::cout << ScalarConverter::getInt(str);
    else
    {
        long double d = ScalarConverter::getDouble(str);
        if(d < static_cast <long double> (std::numeric_limits<int>::min())
            || d > static_cast <long double> (std::numeric_limits<int>::max()))
            std::cout << "impossible";
        else
            std::cout << static_cast <int> (d);
    }
    std::cout << std::endl;
}

void ScalarConverter::printFloat(char type, std::string str)
{
    std::cout << "float: ";
    if(!type || type == 'c')
        std::cout << "nanf";
    else if (type == 'i')
        std::cout << static_cast <float> (ScalarConverter::getInt(str)) << "f";
    else if (type == 'f')
        std::cout << ScalarConverter::getFloat(str) << "f";
    else if (type == 'd')
    {
        long double d = ScalarConverter::getDouble(str);
        if (d < static_cast <long double> (-std::numeric_limits<float>::max()))
            std::cout << "-inff";
        else if (d > static_cast <long double> (std::numeric_limits<float>::max()))
            std::cout << "+inff";        
        else
            std::cout << static_cast <float> (ScalarConverter::getDouble(str)) << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(char type, std::string str)
{
    std::cout << "double: ";
    if(!type || type == 'c')
        std::cout << "nan";
    else if (type == 'i')
        std::cout << static_cast <double> (ScalarConverter::getInt(str));
    else if (type == 'f')
        std::cout << static_cast <double>(ScalarConverter::getFloat(str));
    else if (type == 'd')
    {
        long double d = ScalarConverter::getDouble(str);
        if (d < static_cast <long double> (-std::numeric_limits<double>::max()))
            std::cout << "-inf";
        else if (d > static_cast <long double> (std::numeric_limits<double>::max()))
            std::cout << "+inf";        
        else
            std::cout << ScalarConverter::getDouble(str);
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    char type;

    type = ScalarConverter::getType(str);
    ScalarConverter::printChar(type, str);
    ScalarConverter::printInt(type, str);
    ScalarConverter::printFloat(type, str);
    ScalarConverter::printDouble(type, str);
}