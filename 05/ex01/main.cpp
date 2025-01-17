#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form form;
    Form form2(form);
    std::cout << form << std::endl;
    std::cout << form2 << std::endl;


    try
    {
        Form test("big form", 0, 150);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    Form *f;
    f = NULL;
    try
    {
        f = new Form("big form", 10, 150);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    if (f)
        std::cout << *f << std::endl;
    else
        return(1);
    
    
    Bureaucrat toto("toto", 20);

    std::cout << toto << std::endl;

    toto.signForm(*f);
    delete f;
    toto.signForm(form);
    return(0);
}