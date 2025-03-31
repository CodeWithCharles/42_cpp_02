/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:36:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 12:45:10 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int	main(int argc, char *argv[])
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);
	float	x(0);
	float	y(0);

	if (argc != 3)
		std::cout << "Usage: bsp <x> <y>" << std::endl;
	else
	{
		x = atof(argv[1]);
		y = atof(argv[2]);
		std::cout << "bsp = " << (bsp(a, b, c, Point(x, y))
			== true ? "True" : "False") << std::endl;
	}

	return (0);
}
