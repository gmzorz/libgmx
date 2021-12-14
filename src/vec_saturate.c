/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_saturate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 13:54:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:20:15 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

/*
**	Clamp (or limit) a vector within the defined range: [0.0 ... 1.0]
**	Commonly used for color ranges
*/
t_vec	saturate(const t_vec vector)
{
	const t_vec	upper = (t_vec){1.0, 1.0, 1.0, 1.0};
	const t_vec	lower = (t_vec){0.0, 0.0, 0.0, 0.0};
	t_cnd4		higher;
	t_cnd4		in_range;

	higher = -__builtin_convertvector(vector > upper, t_cnd4);
	in_range = -__builtin_convertvector(vector > lower, t_cnd4);
	return ((vector - vector * higher + higher) * in_range);
}
