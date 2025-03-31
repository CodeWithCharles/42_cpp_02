/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:36:32 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 11:12:53 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int	main(void)
{
	Fixed	a(2896);
	float	af(2896 * 2896);
	Fixed	b(8388607);
	float	bf(8388607 / 8388607);

	std::cout << std::fixed << std::endl;

	std::cout << a * a << std::endl;
	std::cout << af << std::endl;
	std::cout << b / b << std::endl;
	std::cout << bf << std::endl;
	return (0);
}
