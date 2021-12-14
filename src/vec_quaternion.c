/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_quaternion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 11:39:22 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/11 20:53:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	qmul(const t_vec q1, const t_vec q2)
{
	t_vec	mult;

	mult = (t_vec){
		q1[W] * q2[X] + q1[X] * q2[W] + q1[Y] * q2[Z] - q1[Z] * q2[Y],
		q1[W] * q2[Y] - q1[X] * q2[Z] + q1[Y] * q2[W] + q1[Z] * q2[X],
		q1[W] * q2[Z] + q1[X] * q2[Y] - q1[Y] * q2[X] + q1[Z] * q2[W],
		q1[W] * q2[W] - q1[X] * q2[X] - q1[Y] * q2[Y] - q1[Z] * q2[Z],
	};
	return (normalize(mult));
}


t_vec	qrotate(const t_vec point, const t_vec axis, const float angle)
{
	float	qangle;
	t_vec	qaxis;

	qangle = sinf(angle / 2.f);
	qaxis = (t_vec){
		axis[X] * sinf(qangle),
		axis[Y] * sinf(qangle),
		axis[Z] * sinf(qangle),
		axis[W] * cosf(angle / 2.f),
	};
	return (qmul(point, qaxis));
}
