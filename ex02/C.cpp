#include "C.hpp"

C::~C()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}