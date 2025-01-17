#include <iostream>
#include "Span.hpp"

int main()
{
    Span span(10);

    try
    {
        span.addNumber(20);
        span.addNumber(0);
        span.addNumber(-15);
        span.addNumber(93);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Span span1(span);

    Span span2;

    span2 = span;

    try
    {
        std::cout << "longest spans : "
            << span.longestSpan() << ", "
            << span1.longestSpan() << ", "
            << span2.longestSpan() << std::endl;
        std::cout << "shortest spans : "
            << span.shortestSpan() << ", "
            << span1.shortestSpan() << ", "
            << span2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    int arr[] = {501, 502, 503};
    try
    {
        span.addRange(arr, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    span.print_content();
    span1.print_content();
    span2.print_content();

   try
    {
        std::cout << "longest span: " << span.longestSpan() << std::endl;
        std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    Span test(10000);
    int *bigarr = new int[0];
    if(!bigarr)
        return(1);
    try
    {
        test.addRange(bigarr, 10000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "test for 10000" << std::endl;
        std::cout << "size : " << test.size() << std::endl;
        std::cout << "longest span: " << test.longestSpan() << std::endl;
        std::cout << "shortest span: " << test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete [] bigarr;
    return(0);
}