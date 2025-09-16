#pragma once
#include <iostream>

class Fixed
{
    private :
        int _fixed_point;
        static const int fractional_bits = 8;
    public :
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed();
        Fixed(const Fixed &fix);
        Fixed &operator=(const Fixed &fix);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(const Fixed &f1);
        bool operator<(const Fixed &f1);
        bool operator>=(const Fixed &f1);
        bool operator<=(const Fixed &f1);
        bool operator==(const Fixed &f1);
        bool operator!=(const Fixed &f1);

        Fixed operator+(const Fixed &f1);
        Fixed operator-(const Fixed &f1);
        Fixed operator*(const Fixed &f1);
        Fixed operator/(const Fixed &f1);
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &f1,Fixed &f2);
        static const Fixed &min(const Fixed &f1,const Fixed &f2);
        static Fixed &max(Fixed &f1,Fixed &f2);
        static const Fixed &max(const Fixed &f1,const Fixed &f2);
        
};

std::ostream &operator<<(std::ostream &o,const Fixed &f);