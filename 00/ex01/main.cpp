#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string      cmd;

    while(1)
    {
        std::cout << "> ";
        if(getline(std::cin, cmd).fail())
            return(EXIT_FAILURE);
        phonebook.cmd(cmd);
    }
    return(EXIT_SUCCESS);
}