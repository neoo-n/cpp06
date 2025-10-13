
#include "Serializer.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

Serializer::Serializer()
{
    std::cout << BLUE << "Default Serializer constructor called" << WHITE << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
    std::cout << BLUE << "Copy Serializer constructor called" << WHITE << std::endl;
}

Serializer::~Serializer()
{
    std::cout << YELLOW << "Destructor Serializer called" << WHITE << std::endl;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	std::cout << PINK << "Assignment Serializer called" << WHITE << std::endl;
}


