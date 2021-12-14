/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_min_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:07:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:16:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

/*
**	Returns a vector containing the lowest values out of all components in
**	<v1> and <v2>
*/
t_vec	vmin(const t_vec v1, const t_vec v2)
{
	t_cnd4	is_higher;

	is_higher = -__builtin_convertvector(v1 < v2, t_cnd4);
	return (v2 * ((is_higher - 1.f) * -1.f) + v1 * is_higher);
}

/*
**	Returns a vector containing the highest values out of all components in
**	<v1> and <v2>
*/
t_vec	vmax(const t_vec v1, const t_vec v2)
{
	t_cnd4	is_lower;

	is_lower = -__builtin_convertvector(v1 > v2, t_cnd4);
	return (v2 * ((is_lower - 1.f) * -1.f) + v1 * is_lower);
}
