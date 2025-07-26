#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

// tempated container is defined in the hpp file or tpp file
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(MutantStack const &other) : std::stack<T, Container>(other) {}
    MutantStack &operator=(MutantStack const &other)
    {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    const_iterator begin() const
    {
        return this->c.begin();
    }

    const_iterator end() const
    {
        return this->c.end();
    }

private:
};

// std::ostream &operator<<(std::ostream &o, MutantStack const &infile);

#endif
