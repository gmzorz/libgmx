/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_length.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:07:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:19:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

/*
**	Returns length (or magnitude) of a vector
*/
float	length(const t_vec vector)
{
	return (sqrtf(vector[X] * vector[X]
			+ vector[Y] * vector[Y]
			+ vector[Z] * vector[Z]
			+ vector[W] * vector[W]));
}
