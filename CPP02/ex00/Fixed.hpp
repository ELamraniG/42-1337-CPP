#pragma once
#include <iostream>

class Fixed
{
  private:
	int _fixed_point;
	static const int fractional_bits = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fix);
	Fixed &operator=(const Fixed &fix);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
