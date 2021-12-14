/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/11 20:42:17 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/11 20:52:49 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <libft.h>

void	mat_init(t_mat mat)
{
	const t_mat	identity = {
		(t_vec){1.0, 0.0, 0.0, 0.0},
		(t_vec){0.0, 1.0, 0.0, 0.0},
		(t_vec){0.0, 0.0, 1.0, 0.0},
		(t_vec){0.0, 0.0, 0.0, 1.0}
	};

	ft_memcpy(mat, identity, sizeof(t_mat));
}
