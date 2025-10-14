#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base	b;
	Base 	*temp;
	Base 	*temp1 = b.generate();;

	b.identify(*temp1);

	sleep(1);
	temp = b.generate();
	b.identify(temp);
	

	delete temp;
	temp = NULL;
	delete temp1;
	temp1 = NULL;
	return (0);
}