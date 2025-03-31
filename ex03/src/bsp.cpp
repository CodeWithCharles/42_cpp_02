/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:54:24 by cpoulain          #+#    #+#             */
/*   Updated: 2025/03/31 12:45:47 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/* -------------------------------------------------------------------------- */
/*                              Static prototypes                             */
/* -------------------------------------------------------------------------- */

static bool	_barycentric_is_positive(
	const Point &a,
	const Point &b,
	const Point &p);

/* -------------------------------------------------------------------------- */
/*                           Header implementations                           */
/* -------------------------------------------------------------------------- */

bool	bsp(
	const Point &a,
	const Point &b,
	const Point &c,
	const Point &p
)
{
	if (!_barycentric_is_positive(a, b, p))
		return (false);
	if (!_barycentric_is_positive(b, c, p))
		return (false);
	if (!_barycentric_is_positive(c, a, p))
		return (false);
	return (true);
}

/* -------------------------------------------------------------------------- */
/*                           Static implementations                           */
/* -------------------------------------------------------------------------- */

static bool	_barycentric_is_positive(
	const Point &a,
	const Point &b,
	const Point &p
)
{
	Point	p1(p - a);
	Point	p2(p - b);

	return (Fixed(0) <= p1.det(p2));
}
