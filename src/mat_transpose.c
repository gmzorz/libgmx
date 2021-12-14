/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat_transpose.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/11 20:46:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/11 20:46:30 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

void	mat_transpose(t_mat matrix)
{
	matrix[0][1] += matrix[1][0];
	matrix[1][0] = matrix[0][1] - matrix[1][0];
	matrix[0][1] -= matrix[1][0];
	matrix[0][2] += matrix[2][0];
	matrix[2][0] = matrix[0][2] - matrix[2][0];
	matrix[0][2] -= matrix[2][0];
	matrix[2][1] += matrix[1][2];
	matrix[1][2] = matrix[2][1] - matrix[1][2];
	matrix[2][1] -= matrix[1][2];
}
