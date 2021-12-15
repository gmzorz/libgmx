/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_power.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 15:42:49 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 15:44:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	vpow(const t_vec vector, const float power)
{
	return ((t_vec){
		powf(vector[X], power),
		powf(vector[Y], power),
		powf(vector[Z], power),
		powf(vector[W], power)
	});
}
