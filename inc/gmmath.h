/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gmmath.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:26:41 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 14:04:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMMATH_H
# define GMMATH_H
# include <math.h>

float	min(const float v1, const float v2);
float	max(const float v1, const float v2);
float	clampf(const float num, const float min, const float max);
float	smoothstep(const float edge0, const float edge1, const float x);
float	smoothmin(const float edge0, const float edge1, const float x);
float	lerp(const float v0, const float v1, const float t);

#endif
