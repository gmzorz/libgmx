/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_smoothmin.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:42:57 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:45:20 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmmath.h>
#include <math.h>

float	smoothmin(const float edge0, const float edge1, const float x)
{
	float	num;

	num = max(x - fabs(edge0 - edge1), 0) / x;
	return (min(edge0, edge1) - num * num * num * x * 1 / 6.f);
}
