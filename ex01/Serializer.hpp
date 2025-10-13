
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

# define BLUE "\033[34m"
# define WHITE "\033[0m"
# define RED "\033[0;31m"
# define PINK "\033[1;35m"
# define YELLOW "\033[0;33m"

class Serializer
{
    private:

    public:
        Serializer();
        Serializer(const Serializer &cpy);
        ~Serializer();
        Serializer &operator=(const Serializer &obj);
};

#endif

