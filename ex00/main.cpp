#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 1)
	{
		std::cerr << RED << "You don't have the right number of agruments, try again.";
		std::cerr << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}