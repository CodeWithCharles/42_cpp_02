/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:41:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/27 13:14:37 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Constructors

Fixed::Fixed(): _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = input << Fixed::_raw_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(input * float(1 << Fixed::_fract_bits));
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
	this->_raw_bits = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

// Getters

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw_bits);
}

// Setters

void	Fixed::setRawBits(int const fp_value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_bits = fp_value;
}

// Public functions

float	Fixed::toFloat(void) const
{
	return (float(this->_raw_bits) / float(1 << Fixed::_fract_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_raw_bits >> Fixed::_fract_bits);
}
