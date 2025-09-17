#include "Fixed.hpp"

class Point
{
  private:
	const Fixed x;
	const Fixed y;

  public:
	Point();
	Point(const float f1, const float f2);
	~Point();
	Point(const Point &f);
	Point &operator=(const Point &f);
	float get_x() const;
	float get_y()const ;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);