#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact
{
private:
    std::string keys[5];
    std::string values[5];
    void displayone(std::string str);
public:
    Contact();
    ~Contact();
    void display(int id);
    void displayfull();
    std::string getkey(int id);
    int setvalue(std::string key, std::string value);
};

# endif