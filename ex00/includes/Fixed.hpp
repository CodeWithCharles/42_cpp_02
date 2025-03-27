/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:49:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/27 11:41:44 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
	// Private attributes
		int					_fixed_point_value;
		static const int	_fract_bits;

	public:

	// Constructors
		Fixed();
		Fixed(const Fixed &copy);

	// Deconstructors
		~Fixed();

	// Assignement operators overload
		Fixed	&operator=(const Fixed &org);

	// Getters
		int	getRawBits(void)const;

	// Setters
		void	setRawBits(int const raw);
};
