/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_normalize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:20:46 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 12:04:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <gmmath.h>

t_vec	normalize(const t_vec vector)
{
	return (vector / length(vector));
}
