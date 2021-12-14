/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_dot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:21:40 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 14:08:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

float	dot(const t_vec v1, const t_vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}
