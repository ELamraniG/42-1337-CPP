#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "default constructor called" << std::endl;
}
Point::Point(const float f1, const float f2) : x(f1), y(f2)
{
	// std::cout << "float constructor called" << std::endl;
}
Point::~Point()
{
	// std::cout << "distructor constructor called" << std::endl;
}
Point::Point(const Point &f) : x(f.get_x()) , y(f.get_y())
{
	// std::cout << "copy constructor called" << std::endl;
}
Point &Point::operator=(const Point &f)
{
	// std::cout << "copy assignement called" << std::endl;
	(void)f;
	return *this;
}

float	Point::get_x(void) const
{
	return x.toFloat();
}
float	Point::get_y(void) const
{
	return y.toFloat();
}