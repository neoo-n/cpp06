
#include "Data.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

Data::Data()
: _name("default"), _count(0), _size(0)
{
	if (DEBUG)
		std::cout << BLUE << "Default Data constructor called" << WHITE << std::endl;
}

Data::Data(const Data &cpy)
: _name(cpy._name), _size(cpy._size)
{
	for (int i = 0; i < cpy._size; i++)
	{
		this->_count[i] = cpy._count[i];
	}
	if (DEBUG)
		std::cout << BLUE << "Copy Data constructor called" << WHITE << std::endl;
}

Data::~Data()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor Data called" << WHITE << std::endl;
}

Data &Data::operator=(const Data &obj)
{
	if (this != &obj)
	{
		this->_name = obj._name;
		this->_size = obj._size;
		for (int i = 0; i < obj._size; i++)
		{
			this->_count[i] = obj._count[i];
		}

	}
	if (DEBUG)
		std::cout << PINK << "Assignment Data called" << WHITE << std::endl;
	return (*this);
}


