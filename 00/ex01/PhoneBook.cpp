#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    add_id = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::cmd(std::string arg)
{
    if(!arg.compare("ADD"))
        add();
    if(!arg.compare("SEARCH"))
        search();
    if(!arg.compare("EXIT"))
        exit(EXIT_SUCCESS);
}

void PhoneBook::displayall()
{
    for (int i = 0; i < 8; i++)
        contact[i].display(i);
}

void PhoneBook::displayone(int id)
{
    contact[id].displayfull();
}

void PhoneBook::add()
{
    std::string key;
    std::string res;
    int i;

    i = 0;
    while(i < 5)
    {
        key = contact[0].getkey(i);
        std::cout << key << " : ";
        if(getline(std::cin, res).fail())
            exit(EXIT_FAILURE);
        if(contact[add_id].setvalue(key, res))
            std::cout << "Uncorrect value" << std::endl;
        else
            i++;
    }
    std::cout << "Contact is setup" << std::endl;
    add_id = (add_id + 1) % 8;
}

void PhoneBook::search()
{
    std::string line;
    int id;

    displayall();
    std::cout << "Contact Id (0 - 7) : ";
    if(getline(std::cin, line).fail())
        exit(EXIT_FAILURE);
    if(!all_of(line.begin(), line.end(), ::isdigit))
    {
        std::cout << "id must be a digit" << std::endl;
        return;
    }
    id = stoi(line);
    if(id < 0 || id > 7)
        std::cout << "id must be between 0 and 7" << std::endl;
    else
        contact[id].displayfull();
}