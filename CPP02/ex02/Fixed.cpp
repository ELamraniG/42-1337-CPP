#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int n) : _fixed_point(n << fractional_bits)
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixed_point(roundf(n * (1 << fractional_bits)))
{
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fix) 
{
	std::cout << "Copy assignement called" << std::endl;
	this->_fixed_point = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}
float Fixed::toFloat(void) const
{
	return (float)getRawBits() / (1 << fractional_bits);
}
int Fixed::toInt(void) const
{
	return (getRawBits() >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return (o);
}
//>, <, >=, <=, ==, and !=.
bool Fixed::operator>(const Fixed &f1) const
{
	return (this->getRawBits() > f1.getRawBits());
}
bool Fixed::operator<(const Fixed &f1) const
{
	return (this->getRawBits() < f1.getRawBits());
}
bool Fixed::operator>=(const Fixed &f1) const
{
	return (this->getRawBits() >= f1.getRawBits());
}
bool Fixed::operator<=(const Fixed &f1) const
{
	return (this->getRawBits() <= f1.getRawBits());
}
bool Fixed::operator==(const Fixed &f1) const
{
	return (this->getRawBits() == f1.getRawBits());
}

bool Fixed::operator!=(const Fixed &f1)  const
{
	return (this->getRawBits() != f1.getRawBits());
}

Fixed Fixed::operator+(const Fixed &f1)const
{
	Fixed	f;

	f.setRawBits(this->getRawBits() + f1.getRawBits());
	return (f);
}

Fixed Fixed::operator-(const Fixed &f1)const
{
	Fixed	f;

	f.setRawBits(this->getRawBits() - f1.getRawBits());
	return (f);
}

Fixed Fixed::operator*(const Fixed &f1)const
{
	return (Fixed(this->toFloat() * f1.toFloat()));
}

Fixed Fixed::operator/(const Fixed &f1)const
{
	return (Fixed(this->toFloat() / f1.toFloat()));
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}
Fixed const &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() < f2.toFloat() ? f1 : f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}
Fixed const &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() > f2.toFloat() ? f1 : f2);
}

Fixed &Fixed::operator++()
{
	this->_fixed_point++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed	f;

	f = *this;
	this->_fixed_point++;
	return (f);
}
Fixed &Fixed::operator--()
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	f;

	f = *this;
	this->_fixed_point--;
	return (f);
}

void Fixed::randomm(const Fixed &f1)
{
	(void)f1;
	std::cout<<"waayeh\n";
}