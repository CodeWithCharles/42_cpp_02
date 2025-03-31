/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:39:49 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 11:53:35 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"


/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */

Point::Point(void): x(0), y(0) { }

Point::Point(const float x, const float y): x(x), y(y) { }

Point::Point(const Fixed &x, const Fixed &y): x(x), y(y) { }

Point::Point(const Point &point)
{
	*this = point;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructors                                */
/* -------------------------------------------------------------------------- */

Point::~Point(void) { }

/* -------------------------------------------------------------------------- */
/*                        Assignement operator overload                       */
/* -------------------------------------------------------------------------- */

Point	&Point::operator=(const Point &point)
{
	(Fixed)this->x = point.x;
	(Fixed)this->y = point.y;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                           Mathematical operators                           */
/* -------------------------------------------------------------------------- */

Point	Point::operator+(const Point &point) const
{
	return (Point(this->x + point.x, this->y + point.y));
}

Point	Point::operator-(const Point &point) const
{
	return (Point(this->x - point.x, this->y - point.y));
}

Point	Point::operator*(const Point &point) const
{
	return (Point(this->x * point.x, this->y * point.y));
}

Point	Point::operator/(const Point &point) const
{
	return (Point(this->x / point.x, this->y / point.y));
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

Fixed	Point::dot(const Point &point)
{
	return (this->x * point.x + this->y * point.y);
}

Fixed	Point::det(const Point &point)
{
	return (this->x * point.y - this->y * point.x);
}
