#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class Span
{
public:
    Span(unsigned int);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int);
    int shortestSpan() const;
    int longestSpan() const;
    
    template <typename ItType>
    void addRange(ItType start, ItType end)
    {
        unsigned int amount = end - start;
        if (v.size() + amount > maxSize)
            throw std::runtime_error("Error: Span is full, items can't be added");
        v.insert(v.end(), start, end);
    }

private:
    unsigned int maxSize;
    Span();
    std::vector<int> v;
};

std::ostream &operator<<(std::ostream &o, Span const &infile);

#endif
