/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_trig.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:48:50 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:50:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	vsin(const t_vec vector)
{
	return ((t_vec){
		sinf(vector[X]),
		sinf(vector[Y]),
		sinf(vector[Z]),
		sinf(vector[W])
	});
}

t_vec	vcos(const t_vec vector)
{
	return ((t_vec){
		cosf(vector[X]),
		cosf(vector[Y]),
		cosf(vector[Z]),
		cosf(vector[W])
	});
}

t_vec	vtan(const t_vec vector)
{
	return ((t_vec){
		tanf(vector[X]),
		tanf(vector[Y]),
		tanf(vector[Z]),
		tanf(vector[W])
	});
}
