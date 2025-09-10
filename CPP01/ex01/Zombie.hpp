#pragma once
#include <iostream>


class   Zombie{

    private :
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce( void );
        std::string get_name();
        void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

