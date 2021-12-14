/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_mod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 14:00:19 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 14:01:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

t_vec	vmod(const t_vec v1, const float mod)
{
	return ((t_vec){
		fmod(v1[X], mod),
		fmod(v1[Y], mod),
		fmod(v1[Z], mod),
		fmod(v1[W], mod)
	});
}
