/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_cross.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:33:27 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:36:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_vec	cross(const t_vec v1, const t_vec v2)
{
	return ((t_vec){
		v1[Y] * v2[Z] - v1[Z] * v2[Y],
		v1[Z] * v2[X] - v1[X] * v2[Z],
		v1[X] * v2[Y] - v1[Y] * v2[X]});
}
