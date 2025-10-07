
#include "ScalarConverter.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

ScalarConverter::ScalarConverter()
{
    std::cout << BLUE << "Default ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    std::cout << BLUE << "Copy ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << YELLOW << "Destructor ScalarConverter called" << WHITE << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	std::cout << PINK << "Assignment ScalarConverter called" << WHITE << std::endl;
}

// ----------------------------------------- METHODS -------------------------------------------

bool	invalid_value(const std::string &s)
{
	int	len = s.size();
	
	for (int i = 0 ; i < len ; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	return (true);
}

void	ScalarConverter::convert(const std::string &s)
{
	invalid_value(s);
}
