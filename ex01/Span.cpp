#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : maxSize(n)
{
    std::cout << GREY << "Span default constructor" << RESET << std::endl;

    return;
}
Span::Span(Span const &other)
{
    std::cout << GREY << "Span copy constructor" << RESET << std::endl;
    v = other.v;
    maxSize = other.maxSize;
    return;
}

Span &Span::operator=(Span const &other)
{
    std::cout << GREY << "Span copy assignment operator" << RESET << std::endl;
    if (this != &other)
    {
        v = other.v;
        maxSize = other.maxSize;
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
void Span::addNumber(int n)
{
    if (v.size() < maxSize)
        v.push_back(n);
    else
        throw std::runtime_error("Error: Span is full, item can't be added");
}

int Span::shortestSpan() const
{
    unsigned int span UINT_MAX;
    std::vector<int> sorted = v;

    if (v.size() < 2)
        throw std::runtime_error("There are less than 2 numbers to compare");

    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator it = sorted.begin();
    std::vector<int>::iterator next_it = it;
    ++next_it;

    while (next_it != sorted.end())
    {
        if (static_cast<unsigned int>(*next_it - *it) < span)
            span = static_cast<unsigned int>(*next_it) - static_cast<unsigned int>(*it);
        ++it;
        ++next_it;
    }
    return span;
}
int Span::longestSpan() const
{
    unsigned int span = 0;
    int min_val;
    int max_val;

    if (v.size() < 2)
        throw std::runtime_error("There are less than 2 numbers to compare");
    min_val = *std::min_element(v.begin(), v.end());
    max_val = *std::max_element(v.begin(), v.end());
    span = max_val - min_val;

    return span;
}

/********************************************/
/********************************************/
/****** STREAM ******/

// std::ostream &operator<<(std::ostream &o, const Span &infile)
// {
//     o << "";
//     return o;
// }

/********************************************/
/********************************************/
/****** PRIVATE ******/

Span::Span()
{
    std::cout << GREY << "Span default constructor" << RESET << std::endl;
    return;
}
