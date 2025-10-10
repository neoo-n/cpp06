
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

void	check_put_zero(const std::string &s, size_t point_place, size_t str_len, bool &put_zero)
{
	for (size_t i = point_place + 1; i < str_len; i++)
		{
			if (s[i] != '0')
			{
				if (!(i == str_len - 1 && s[i] == 'f'))
					put_zero = false;
			}
		}
}

void	check_float(const std::string &s, size_t point_place, size_t str_len)
{
	float		value;
	bool		put_zero = true;

	for (size_t i = 0; i < str_len; i++)
	{
		if (!isdigit(s[i]))
			if (s[i] != '.' && !(s[i] == 'f' && i == str_len - 1))
				throw std::invalid_argument("Invalid argument 1");
	}
	value = atof(s.c_str());
	if (value >= 20 && value <= 126)
		std::cout << "char : " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(value) << std::endl;
	std::cout << "float : " << static_cast<float>(value);
	check_put_zero(s, point_place, str_len, put_zero);
	if (put_zero)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(value);
	if (put_zero)
		std::cout << ".0";
	std::cout << std::endl;
}

void	check_double_float(const std::string &s, size_t point_place, size_t str_len)
{
	if (point_place != s.rfind('.'))
		throw std::invalid_argument("Invalid argument 2");
	if (s.find('f'))
		check_float(s, point_place, str_len);
	else
	{
		for (size_t i = 0; i < str_len; i++)
		{
			if (!isdigit(s[i]) && s[i] != '.')
				throw std::invalid_argument("Invalid argument 3");
		}
	}
}

void	check_int(const std::string &s, size_t str_len)
{
	int	value;
	for(size_t i = 0; i < str_len; i++)
		if (!isdigit(s[i]))
			throw std::invalid_argument("Invalid argument 4");
	value = atoi(s.c_str());
	if (value >= 20 && value <= 126)
		std::cout << "char : " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(value) << std::endl;
	std::cout << "float : " << static_cast<float>(value) << std::endl;
	std::cout << "double : " << static_cast<double>(value) << std::endl;

}

void	pseudo_literals(const std::string &s)
{
	
}

void	ScalarConverter::convert(const std::string &s)
{
	size_t	point_place = 0;
	size_t	str_len = s.size();
	if (str_len == 1)
	{
		std::cout << "char : " << static_cast<char>(s[0]) << std::endl;
		std::cout << "int : " << static_cast<int>(s[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(s[0]) << std::endl;
		std::cout << "double : " << static_cast<double>(s[0]) << std::endl;
	}
	else
	{
		point_place = s.find('.');
		if (point_place != s.npos)
			check_double_float(s, point_place, str_len);
		else
			check_int(s, str_len);
	}
}
