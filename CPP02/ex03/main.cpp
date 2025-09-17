/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:17:25 by mohaben-          #+#    #+#             */
/*   Updated: 2025/08/06 21:42:30 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 0);
	Point b(6, 0);
	Point c(3, 6);

	Point p1(3, 2);   // inside T
	Point p2(6, 0);   // on point b F
	Point p3(3, 0);   // on edge F
	Point p4(8, 3);   // outside F
	Point p5(1, 5);   // outside F
	Point p6(2, 3);   // inside T

	std::cout << "p1: " << (bsp(a, b, c, p1) == true ? "true" : "false") << std::endl;
	std::cout << "p2: " << (bsp(a, b, c, p2) == true ? "true" : "false") << std::endl;
	std::cout << "p3: " << (bsp(a, b, c, p3) == true ? "true" : "false") << std::endl;
	std::cout << "p4: " << (bsp(a, b, c, p4) == true ? "true" : "false") << std::endl;
	std::cout << "p5: " << (bsp(a, b, c, p5) == true ? "true" : "false") << std::endl;
	std::cout << "p6: " << (bsp(a, b, c, p6) == true ? "true" : "false") << std::endl;
	return (0);
}