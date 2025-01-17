#include <iostream>

void print_str_upper(char *str)
{
    if(!str)
        return;
    for (size_t i = 0; i < strlen(str) ; i++)
        std::cout << (char)(toupper(str[i]));
}


int main(int argc, char **argv)
{
    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
        print_str_upper(argv[i]);
    std::cout << std::endl;
    return (0);
}