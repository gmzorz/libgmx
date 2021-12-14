/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_normalize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:20:46 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/23 14:21:15 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_vec	normalize(const t_vec vector)
{
	return (vector / length(vector));
}
