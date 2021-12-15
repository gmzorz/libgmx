/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   global.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 10:24:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 16:09:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include <gmxui.h>

void	gmx_frameloop(
			t_gmx *user,
			t_vec (*frag_out)(const t_fragment),
			t_fragment frag);

#endif
