
#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

# define BLUE "\033[34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define PINK "\033[1;35m"
# define YELLOW "\033[0;33m"
# define DEBUG false

class Data
{
	private:
		std::string _name;
		int			*_count;
		int			_size;

	public:
		Data();
		Data(const Data &cpy);
		~Data();
		Data &operator=(const Data &obj);
};

#endif

