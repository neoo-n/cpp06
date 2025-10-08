
#include "ScalarConverter.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

ScalarConverter::ScalarConverter()
{
    std::cout << BLUE << "Default ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
    std::cout << BLUE << "Copy ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << YELLOW << "Destructor ScalarConverter called" << WHITE << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	std::cout << PINK << "Assignment ScalarConverter called" << WHITE << std::endl;
	return (*this);
}

// ----------------------------------------- METHODS -------------------------------------------

void	check_float(const std::string &s)
{
	size_t	point_place = s.find('.');

	if (point_place == s.npos)
		throw std::invalid_argument("Invalid argument");
}

void	check_double(const std::string &s)
{
(void)s;
}

void	check_int(const std::string &s)
{
(void)s;

}

void	ScalarConverter::convert(const std::string &s)
{
	if (s.size() == 1)
	{
		std::cout << "char : " << static_cast<char>(s[0]) << std::endl;
		std::cout << "int : " << static_cast<int>(s[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(s[0]) << std::endl;
		std::cout << "double : " << static_cast<double>(s[0]) << std::endl;
	}
	else
	{
		if (s.find('f'))
			check_float(s);
		else if (s.find('.'))
			check_double(s);
		else
			check_int(s);
	}
}
