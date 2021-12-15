/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_abs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:26:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 15:27:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	vabs(const t_vec vector)
{
	return ((t_vec){
		fabs(vector[X]),
		fabs(vector[Y]),
		fabs(vector[Z]),
		fabs(vector[W])
	});
}
