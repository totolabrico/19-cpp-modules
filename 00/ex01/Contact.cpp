#include "Contact.hpp"

Contact::Contact()
{   
    keys[0] = "firstname";
    keys[1] = "lastname";
    keys[2] = "nickname";
    keys[3] = "number";
    keys[4] = "secret";
    for (int i  = 0; i < 5; i++)
        values[i] = "EMPTY";
}

Contact::~Contact()
{
}
void Contact::display(int id)
{
    std::string s;

    std::cout << "         " << id;
    for (int i  = 0; i < 3; i++)
    {
        std::cout << "|";
        displayone(values[i]);
    }
    std::cout << std::endl;
}

void Contact::displayone(std::string str)
{
    std::string res;
    res = str.substr(0,10);
    if(res.length() == 10)
        res.at(9) = '.';
    while(res.length() < 10)
        res = ' ' + res;
    std::cout << res;
}

void Contact::displayfull()
{
    for (int i  = 0; i < 5; i++)
        std::cout << keys[i] << " :\t" << values[i] << std::endl;
}

std::string Contact::getkey(int id)
{
    return(keys[id]);
}

int Contact::setvalue(std::string key, std::string value)
{
    for (int i = 0; i < 5; i++)
    {
        if(key.compare(keys[i]) == 0)
        {
            if (!key.compare("number") && !all_of(value.begin(), value.end(), ::isdigit))
                return (EXIT_FAILURE);
            else
            {
                values[i] = value;
                break;
            }
        }
    }
    return (EXIT_SUCCESS);
}