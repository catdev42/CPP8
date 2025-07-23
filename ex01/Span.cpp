#include "Span.hpp"
#include <iostream>
Span::Span(unsigned int n): maxSize(n)
{
    std::cout << GREY << "Span default constructor" << RESET << std::endl;
    
    return;
}
Span::Span(Span const &other)
{
    std::cout << GREY << "Span copy constructor" << RESET << std::endl;
    ;
    return;
}

Span &Span::operator=(Span const &other)
{
    std::cout << GREY << "Span copy assignment operator" << RESET << std::endl;
    if (this != &other)
    {
      /*TODO*/;
    }
    return *this;
}

Span::~Span()
{
    std::cout << GREY << "Span destructor" << RESET << std::endl;
    return;
}

/********************************************/
/********************************************/
/****** MEMBER FUNCTIONS ******/

/********************************************/
/********************************************/
/****** STREAM ******/

std::ostream &operator<<(std::ostream &o, const Span &infile)
{
    o << "";
    return o;
}

/********************************************/
/********************************************/
/****** PRIVATE ******/

Span::Span()
{
    std::cout << GREY << "Span default constructor" << RESET << std::endl;
    return;
}
