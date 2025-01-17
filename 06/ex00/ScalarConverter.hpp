#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <limits>
#include <cfloat>
#include <cerrno>

class ScalarConverter
{
private:
    static char getType(std::string str);
    static int  getInt(std::string str);
    static float  getFloat(std::string str);
    static long double  getDouble(std::string str);
    static void printChar(char type, std::string str);
    static void printInt(char type, std::string str);
    static void printFloat(char type, std::string str);
    static void printDouble(char type, std::string str);

public:
    static void convert(std::string);
};

#endif