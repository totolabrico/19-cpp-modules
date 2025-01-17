#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
    std::ifstream database;
    std::string line;
    std::pair<std::string, float>  pair;

    database.open("data.csv");
    while(getline(database, line))
    {
        std::stringstream stream(line);
        getline(stream, pair.first, ',');
        stream >> pair.second;
        _data.insert(pair);
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & src)
{
    if( this != &src)
        _data = src._data;
    return *this;
}

void BitcoinExchange::doConvert(std::pair<std::string, float> const & pair) const
{
    typedef std::map<std::string, float>::const_iterator const_it;

    const_it it = _data.begin();
    const_it ite = _data.end();
    float res = 0;

    while(it != ite)
    {
        if((it->first.compare(pair.first)) > 0)
        {
            std::cout << pair.first << "=> " << pair.second << " = " << res * pair.second << std::endl;
            return;
        }
        res = it->second;
        it++;
    }
}
