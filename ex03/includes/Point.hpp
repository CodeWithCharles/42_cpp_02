/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:30:49 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 11:52:33 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:

/* ------------------------------ Constructors ------------------------------ */
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &point);

/* ------------------------------- Destructors ------------------------------ */
		~Point(void);

/* ---------------------- Assignement operator overload --------------------- */
		Point	&operator=(const Point &point);

/* ------------------------- Mathematical operators ------------------------- */
		Point	operator+(const Point &point) const;
		Point	operator-(const Point &point) const;
		Point	operator*(const Point &point) const;
		Point	operator/(const Point &point) const;

/* ---------------------------- Public functions ---------------------------- */
		Fixed	dot(const Point &point);
		Fixed	det(const Point &point);
};

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif
