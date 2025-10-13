#include "Data.hpp"
#include "Serializer.hpp"

int	main()
{
	Data		*d = NULL;
	uintptr_t	x;

	std::cout << "d address : " << &d << std::endl;
	x = Serializer::serialize(d);
	std::cout << "x : " << x << std::endl;
	d = Serializer::deserialize(x);
	std::cout << "d address : " << &d << std::endl;
	return (0);
}