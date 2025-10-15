
#include "ScalarConverter.hpp"

// ------------------------------ CONSTRUCTORS AND DESTRUCTOR -------------------------------------

ScalarConverter::ScalarConverter()
{
	if (DEBUG)
		std::cout << BLUE << "Default ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
	if (DEBUG)
		std::cout << BLUE << "Copy ScalarConverter constructor called" << WHITE << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor ScalarConverter called" << WHITE << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	if (DEBUG)
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

void	print_double_float(const std::string &s, bool put_zero)
{
	float	value;

	value = atof(s.c_str());
	if (value >= 32 && value <= 126)
		std::cout << "char : \'" << static_cast<char>(value) << "\'" << std::endl;
	else if ((value >= 0 && value < 32) || value == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(value) << std::endl;
	std::cout << "float : " << static_cast<float>(value);
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
	bool	put_zero = true;
	size_t	i = 0;

	if (point_place != s.rfind('.'))
		throw std::invalid_argument("Invalid argument");
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (i < str_len)
	{
		if (!std::isdigit(s[i]))
			if (s[i] != '.' && !(s[i] == 'f' && i == str_len - 1))
				throw std::invalid_argument("Invalid argument");
		i++;
	}
	check_put_zero(s, point_place, str_len, put_zero);
	print_double_float(s, put_zero);
}

void	print_pl(const std::string &s, int good)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << s;
	if (good == 1)
		std::cout << "f";
	std::cout << std::endl;
	if (good == 1)
		std::cout << "double : " << s << std::endl;
	else
	{
		std::string sd = s;
		sd = sd.erase(sd.size() - 1, 1);
		std::cout << "double : " << sd << std::endl;
	}
}

void	pseudo_literals(const std::string &s)
{
	std::string	pl[4] = {"nan", "inf", "+inf", "-inf"};
	int			good = 0;

	for (int i = 0; i < 4; i++)
	{
		if (!s.compare(pl[i]))
			good = 1;
		else if (!s.compare(pl[i] + "f"))
			good = 2;
	}
	if (good)
		print_pl(s, good);
	else
		throw std::invalid_argument("Invalid argument");
}

void	check_int(const std::string &s, size_t str_len)
{
	int		value;
	size_t	i = 0;

	if (s[i] == '-' || s[i] == '+')
		i++;
	while (i < str_len)
	{
		if (!std::isdigit(s[i]))
		{
			pseudo_literals(s);
			return ;
		}
		i++;
	}
	value = atoi(s.c_str());
	if (value >= 20 && value <= 126)
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;
	else if ((value >= 0 && value < 20) || value == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	std::cout << "int : " << static_cast<int>(value) << std::endl;
	std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;

}

void	ScalarConverter::convert(const std::string &s)
{
	size_t	point_place = 0;
	size_t	str_len = s.size();
	if (str_len == 1 && !std::isdigit(s[0]))
	{
		std::cout << "char : \'" << static_cast<char>(s[0]) << "\'" << std::endl;
		std::cout << "int : " << static_cast<int>(s[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(s[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(s[0]) << ".0" << std::endl;
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
