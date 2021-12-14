/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 14:33:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/22 14:37:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H
# include <vec.h>

typedef t_vec		t_mat[4];

void	m_mul(t_mat dst, const t_mat src); //
t_vec	m_mulv(const t_mat matrix, const t_vec vector); //
t_vec	m_muld(const t_mat matrix, const t_vec vector);
void	m_identity(t_mat matrix);
void	m_transpose(t_mat matrix);

#endif
