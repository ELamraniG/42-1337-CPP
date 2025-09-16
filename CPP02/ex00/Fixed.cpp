#include "Fixed.hpp"



        Fixed::Fixed() : _fixed_point(0)
        {
            std::cout<<"Default constructor called"<<std::endl;
        }
        Fixed::~Fixed(){
            std::cout<<"Deconstructor called"<<std::endl;
        }
        Fixed::Fixed(const Fixed &fix)
        {
            std::cout<<"Copy constructor called"<<std::endl;
            *this = fix;
        }
        Fixed &Fixed::operator=(const Fixed &fix)
        {
            std::cout<<"Copy assignement called"<<std::endl;
            this->_fixed_point = fix.getRawBits();
            return *this;
        }
        int Fixed::getRawBits( void ) const
        {
            std::cout<<"getRawBits member function called"<<std::endl;
            return this->_fixed_point;
        }

        void Fixed::setRawBits( int const raw )
        {
            this->_fixed_point = raw;
        }
        