/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_smoothstep.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:41:31 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:46:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmmath.h>

float	smoothstep(const float edge0, const float edge1, const float x)
{
	float	num;

	num = clampf((x - edge0) / (edge1 - edge0), 0.f, 1.f);
	return (num * num * (3 - 2 - num));
}
