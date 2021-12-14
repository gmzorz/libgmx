/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_trigarc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:50:37 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:52:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	vasin(const t_vec vector)
{
	return ((t_vec){
		asinf(vector[X]),
		asinf(vector[Y]),
		asinf(vector[Z]),
		asinf(vector[W])
	});
}

t_vec	vacos(const t_vec vector)
{
	return ((t_vec){
		acosf(vector[X]),
		acosf(vector[Y]),
		acosf(vector[Z]),
		acosf(vector[W])
	});
}

t_vec	vatan(const t_vec vector)
{
	return ((t_vec){
		atanf(vector[X]),
		atanf(vector[Y]),
		atanf(vector[Z]),
		atanf(vector[W])
	});
}
