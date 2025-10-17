#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base	b;
	Base 	*temp;
	Base 	*temp_ref = generate();

	if (temp_ref)
	{
		Base 	&temp1 = *temp_ref;
		identify(temp1);
	}
	else
		std::cerr << "Error : bad allocation with new" << std::endl;

	sleep(1);
	temp = generate();
	if (temp)
		identify(temp);
	else
		std::cerr << "Error : bad allocation with new" << std::endl;

	delete temp;
	temp = NULL;
	delete temp_ref;
	return (0);
}