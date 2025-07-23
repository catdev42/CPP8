#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Span {  
public:
    Span(unsigned int);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int);
    int shortestSpan() const;
    int longestSpan() const;
private:
    unsigned int maxSize;
    Span();
    std::vector<int> v;
};

std::ostream &operator<<(std::ostream &o, Span const &infile);

#endif
