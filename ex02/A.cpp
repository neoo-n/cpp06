#include "A.hpp"

A::~A()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}