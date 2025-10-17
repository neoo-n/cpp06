#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

// ---------------------------------- DETRUCTOR -------------------------------------------
Base::~Base()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}

// ----------------------------------- METHODS ------------------------------------------
Base	*generate(void)
{
	int	random;
	srand(time(0));
	random = rand() % 3;

	std::cout << random << std::endl;
	switch (random)
	{
		case 0:
			return (new(std::nothrow) A());
		case 1:
			return (new(std::nothrow) B());
		default:
			return (new(std::nothrow) C());
	}
}

void	identify(Base* p)
{
	if (!dynamic_cast<A *>(p))
	{
		if (!dynamic_cast<B *>(p))
		{
			if (!dynamic_cast<C *>(p))
				std::cerr << RED << "Ivalid derived class" << std::endl << WHITE;
			else
				std::cout << "It is of class C" << std::endl;
		}
		else
			std::cout << "It is of class B" << std::endl;
	}
	else
		std::cout << "It is of class A" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		Base &temp = dynamic_cast<A &>(p);
		(void)temp;
		std::cout << "It is of class A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			Base &temp = dynamic_cast<B &>(p);
			(void)temp;
			std::cout << "It is of class B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				Base &temp = dynamic_cast<C &>(p);
				(void)temp;
				std::cout << "It is of class C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << RED << "Ivalid derived class : " << std::endl;
				std::cerr << e.what() << std::endl << WHITE;
			}
			
		}
		
	}
	
	
}
