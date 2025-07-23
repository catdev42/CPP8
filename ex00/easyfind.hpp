#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

#ifndef COLOR
#define COLOR
#define GREY "\033[0;30m"
#define RESET "\033[0m"
#endif

class NotFoundException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T var, int num)
{
    int *p = (typename T::value_type *)0;
    (void)p;

    typename T::iterator it = std::find(var.begin(), var.end(), num);

    if (it == var.end())
        throw NotFoundException();

    return it;
}

// class easyfind {
// public:
//     easyfind();
//     easyfind(easyfind const &other);
//     easyfind &operator=(easyfind const &other);
//     ~easyfind();
// private:
// };

// std::ostream &operator<<(std::ostream &o, easyfind const &infile);

#endif
