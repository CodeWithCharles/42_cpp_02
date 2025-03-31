/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:41:52 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 11:16:19 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Constructors

Fixed::Fixed(): _raw_bits(0) { }

Fixed::Fixed(const int input)
{
	this->_raw_bits = input << Fixed::_raw_bits;
}

Fixed::Fixed(const float input)
{
	this->_raw_bits = roundf(input * float(1 << Fixed::_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

// Destructors

Fixed::~Fixed() { }

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

//		Mathematical operators

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	res;

	res._raw_bits = this->_raw_bits + fixed._raw_bits;
	return (res);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	res;

	res._raw_bits = this->_raw_bits - fixed._raw_bits;
	return (res);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	res._raw_bits = (long(this->_raw_bits)
		* long(fixed._raw_bits)) >> Fixed::_fract_bits;
	return (res);
}


Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	res._raw_bits = (long(this->_raw_bits)
		<< long(Fixed::_fract_bits)) / fixed._raw_bits;
	return (res);
}

//		Assignation operators

//			Incremental

Fixed	&Fixed::operator++(void)
{
	this->_raw_bits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);

	this->_raw_bits++;
	return (*this);
}

//			Decremental

Fixed	&Fixed::operator--(void)
{
	this->_raw_bits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);

	this->_raw_bits--;
	return (*this);
}

//		Comparison operators

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->_raw_bits > fixed._raw_bits);
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->_raw_bits < fixed._raw_bits);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->_raw_bits >= fixed._raw_bits);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->_raw_bits <= fixed._raw_bits);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->_raw_bits == fixed._raw_bits);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->_raw_bits != fixed._raw_bits);
}

//		Static comparison functions

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

// Getters

int	Fixed::getRawBits(void) const
{
	return (this->_raw_bits);
}

// Setters

void	Fixed::setRawBits(int const fp_value)
{
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
