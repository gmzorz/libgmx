/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gmmath.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:26:41 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 12:36:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMMATH_H
# define GMMATH_H
# include <math.h>
# define EPSILON 		1e-8
# define EPSILON_2 		1e-4
# define EPSILON_4		1e-2

float	min(const float v1, const float v2);
float	max(const float v1, const float v2);
float	clampf(const float num, const float min, const float max);
float	smoothstep(const float edge0, const float edge1, const float x);
float	smoothmin(const float edge0, const float edge1, const float x);
float	lerp(const float v0, const float v1, const float t);

#endif
