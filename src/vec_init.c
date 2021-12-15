/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:54:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 15:34:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <stdarg.h>
#include <stdint.h>

t_vec	vec(const float num)
{
	return ((t_vec){num, num, num, num});
}

t_vec	vec2(const float x, const float y)
{
	return ((t_vec){x, y, 0.f, 0.f});
}

t_vec	vec3(const float x, const float y, const float z)
{
	return ((t_vec){x, y, z, 0.f});
}

t_vec	vec4(const float x, const float y, const float z, const float w)
{
	return ((t_vec){x, y, z, w});
}
