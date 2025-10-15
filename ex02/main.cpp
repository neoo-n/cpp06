#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base	b;
	Base 	*temp;
	Base 	&temp1 = *generate();;

	identify(temp1);

	sleep(1);
	temp = generate();
	identify(temp);
	

	delete temp;
	temp = NULL;
	delete &temp1;
	return (0);
}