/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   global.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 10:19:40 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/09 14:31:22 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

t_gmx	*gmx_global(t_gmx *init)
{
	static t_gmx	*gmx = NULL;

	if (init != NULL && gmx == NULL)
		gmx = init;
	return (gmx);
}
