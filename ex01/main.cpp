#include <iostream>
#include "Span.hpp"

int main(){
	Span spanny(10);
	int myints[] = {1,2,5,7,9,15,23, 2147483647, -2147483645};
	spanny.addRange(myints, myints+9);
	std::cout << spanny.shortestSpan() << std::endl;
	std::cout << spanny.longestSpan() << std::endl;
}

