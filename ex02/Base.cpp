#include "Base.hpp"

// ---------------------------------- DETRUCTOR -------------------------------------------
Base::~Base()
{
	if (DEBUG)
		std::cout << YELLOW << "Destructor called" << std::endl << WHITE;
}

// ----------------------------------- METHODS ------------------------------------------
Base	*Base::generate(void)
{
	int	random;
	srand(time(0));
	random = rand() % 3;

	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
}

void	Base::identify(Base* p)
{
	
}

