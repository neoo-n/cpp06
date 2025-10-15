#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

# define BLUE "\033[34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define PINK "\033[1;35m"
# define YELLOW "\033[0;33m"
# define DEBUG false

class Base
{
	private:

	public:
		virtual	~Base();

};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif