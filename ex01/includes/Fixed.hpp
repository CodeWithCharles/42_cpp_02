/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:49:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/27 12:03:04 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#define _FRACT_BITS	8;

class Fixed
{
	private:
	// Private attributes
		int					_fixed_point_value;
		static const int	_fract_bits = _FRACT_BITS;

	public:

	// Constructors
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &copy);

	// Deconstructors
		~Fixed();

	// Assignement operators overload
		Fixed	&operator=(const Fixed &org);

	// Public functions
		float toFloat(void) const;
		int toInt(void) const;

	// Getters
		int	getRawBits(void) const;

	// Setters
		void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
