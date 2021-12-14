/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:54:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 14:11:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <stdarg.h>
#include <stdint.h>

/*
**	Initialize a vector with <c> parameters
*/
t_vec	vec(const int count, ...)
{
	int32_t	idx;
	t_vec	outvec;
	va_list	vec_args;

	idx = 0;
	va_start(vec_args, count);
	while (idx < 4)
	{
		if (idx >= count)
			outvec[idx] = 0.f;
		else
			outvec[idx] = (float)va_arg(vec_args, double);
		idx += 1;
	}
	va_end(vec_args);
	return (outvec);
}
