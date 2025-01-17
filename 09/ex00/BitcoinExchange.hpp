#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

class BitcoinExchange
{
    private:
        std::map <std::string, float> _data;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();
        BitcoinExchange &operator=(BitcoinExchange const & src);
        void doConvert(std::pair<std::string, float> const & pair) const;
};

#endif