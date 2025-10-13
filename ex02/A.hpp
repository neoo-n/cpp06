#ifndef A_HPP
# define A_HPP

# include <iostream>
# include "Base.hpp"

# define BLUE "\033[34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define PINK "\033[1;35m"
# define YELLOW "\033[0;33m"
# define DEBUG false

class A : public Base
{
	private:

	public:
		~A();
};

#endif