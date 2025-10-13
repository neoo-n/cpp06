#include "Base.hpp"

// ---------------------------------- DETRUCTOR -------------------------------------------
Base::~Base()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}
