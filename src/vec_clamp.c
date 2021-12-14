/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_clamp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 12:10:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:19:27 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

/*
**	Clamp (or limit) a vector within a range defined by <min> and <max>
*/
t_vec	clamp(const t_vec vector, const float min, const float max)
{
	t_vec	outvec;
	t_vec	upper;
	t_vec	lower;
	t_cnd4	is_higher;
	t_cnd4	is_lower;

	upper = (t_vec){max, max, max, max};
	lower = (t_vec){min, min, min, min};
	is_higher = -__builtin_convertvector(vector > upper, t_cnd4);
	is_lower = -__builtin_convertvector(vector < lower, t_cnd4);
	outvec = vector - vector * is_higher + is_higher * max;
	return (outvec - outvec * is_lower + is_lower * min);
}
