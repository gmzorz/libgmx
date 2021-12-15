/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shader_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 16:54:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 14:31:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

HRESULT	gmx_add_fragshader(
	t_vec (*frag_out)(const t_fragment))
{
	t_gmx		*user;
	t_shadersrc	*new;
	t_shadersrc	*last;

	user = gmx_global(NULL);
	if (user->shaders == NULL)
	{
		new = ft_calloc(1, sizeof(t_shadersrc));
		new->frag_out = frag_out;
		user->shaders = new;
		return (GMX_SUCCESS);
	}
	last = user->shaders;
	while (last->next != NULL)
		last = last->next;
	new = (t_shadersrc *)ft_calloc(1, sizeof(t_shadersrc));
	if (new == NULL)
		return (GMX_MEMERR);
	new->frag_out = frag_out;
	last->next = new;
	return (GMX_SUCCESS);
}
