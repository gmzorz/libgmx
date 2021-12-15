/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   geometry.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:03:49 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 11:17:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

HRESULT	gmx_add_geometry(void *geometry)
{
	t_geosrc	*last;

	last = gmx_global(NULL)->geometry;
	while (last)
		last = last->next;
	last = (t_geosrc *)ft_calloc(1, sizeof(t_geosrc));
	if (last == NULL)
		return (GMX_MEMERR);
	last->geo = geometry;
	return (GMX_SUCCESS);
}
