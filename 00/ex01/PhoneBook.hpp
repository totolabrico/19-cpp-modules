#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private:
    Contact contact[8];
    int     add_id;
public:
    PhoneBook();
    ~PhoneBook();
    void cmd(std::string arg);
    void displayall();
    void displayone(int id);
    void search();
    void add();
};

# endif