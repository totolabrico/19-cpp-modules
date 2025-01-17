#include <iostream>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

static bool dateIsValid(std::string date)
{
    std::string temp;
    int year;
    int month;
    int day;

    std::stringstream stream(date);
    getline(stream, temp, '-');
    year = atoi(temp.c_str());
    getline(stream, temp, '-');
    month = atoi(temp.c_str());
    if(month < 1 || month > 12)
        return(false);
    stream >> day;
    if(day < 1)
        return (false);
    switch (month)
    {
    case 2:
        if(year % 4 == 0 && year % 100 != 0)
        {
            if(day > 29)
                return (false);
        }
        else if(day > 28)
                return (false);
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if(day > 31)
            return (false);
        break;
    default:
        if(day > 30)
            return (false);
        break;
    }
    return(true);
}

static bool isDateFormat(std::string str)
{
    char c;

    if(str.size() < 10 || str.size() > 11)
        return(false);
    for (long unsigned int i = 0; i < str.size(); i++)
    {
        c = str[i];
    if(i == 4 || i == 7)
    {
        if(c != '-')
            return(false);
    }
    else if (i == 10)
    {
        if (c != ' ')
            return(false);
    }
    else
    {
        if (!isdigit(c))
            return(false);
    }
    }
    return(true);
}

static void exchange(std::ifstream &file)
{
    BitcoinExchange be;
    std::string line;
    std::pair<std::string, float> pair;

    while(getline(file, line))
    {
        std::stringstream stream(line);
        getline(stream, pair.first, '|');
        stream >> pair.second;
        if(!isDateFormat(pair.first));
        else if(!dateIsValid(pair.first))
            std::cout << "Error: bad input => "<< pair.first << std::endl;
        else if(pair.second < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if(pair.second > 1000)
            std::cout << "Error: too large a number." << std::endl;
        else
            be.doConvert(pair);
    }
}

int main(int argc, char **argv)
{

    if(argc != 2)
        return(1);

    std::ifstream file;
    file.open(argv[1]);
    if(!file)
    {
        std::cout << "Error: could not open file." << std::endl;
        return(1);
    }
    exchange(file);
    return(0);
}