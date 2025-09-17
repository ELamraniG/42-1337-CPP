#include "Point.hpp"

// area is (AB-> * AC->) / 2
static float	calculate_the_area(const Point &a, const Point &b,
		const Point &c)
{
	float	AB;
	float	AC;

	AB = b.get_x() - a.get_x() + b.get_y() - a.get_y();
	AC = c.get_x() - a.get_x() + c.get_y() - a.get_y();
	return ((AB - AC) / 2);
}
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float triangle_area_1 = calculate_the_area(a, b, point);
	float triangle_area_2 = calculate_the_area(a, c, point);
	float triangle_area_3 = calculate_the_area(c, b, point);

	float our_area = calculate_the_area(a, b, c);

	if (triangle_area_1 + triangle_area_2 + triangle_area_3 != our_area)
		return (false);

	else
		return (true);
}