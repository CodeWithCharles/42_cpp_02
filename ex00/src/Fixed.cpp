/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:41:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/27 11:51:13 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Defining _fract_bits as it is a const
const int	Fixed::_fract_bits = 8;

// Constructors

Fixed::Fixed(): _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// Destructors

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overload

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixed_point_value = src.getRawBits();
	return (*this);
}

// Functions

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

// Methods

void	Fixed::setRawBits(int const fp_value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = fp_value;
}
