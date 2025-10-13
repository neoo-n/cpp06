#include "B.hpp"

B::~B()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}