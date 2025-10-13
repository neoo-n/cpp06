
#include "Serializer.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

Serializer::Serializer()
{
	if (DEBUG)
		std::cout << BLUE << "Default Serializer constructor called" << WHITE << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
	(void)cpy;
	if (DEBUG)
		std::cout << BLUE << "Copy Serializer constructor called" << WHITE << std::endl;
}

Serializer::~Serializer()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor Serializer called" << WHITE << std::endl;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	if (DEBUG)
		std::cout << PINK << "Assignment Serializer called" << WHITE << std::endl;
	return (*this);
}

// ----------------------------------------- METHODS -------------------------------------------------
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

