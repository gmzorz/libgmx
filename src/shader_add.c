/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shader_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 16:54:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 10:17:35 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

HRESULT		gmx_add_fragshader(
	t_vec (*frag_out)(const t_fragment))
{
	t_shadersrc	*last;

	last = gmx_global(NULL)->shaders;
	
	while (last->next != NULL)
		last = last->next;
	last = (t_shadersrc *)ft_calloc(1, sizeof(t_shadersrc));
	if (last == NULL)
		return (GMX_MEMERR);
	last->frag_out = frag_out;
	return (GMX_SUCCESS);
}
