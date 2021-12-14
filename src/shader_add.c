/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shader_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 16:54:58 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 10:33:23 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

// void	ft_lstadd_back(t_list **alst, t_list *newlist)
// {
// 	if (*alst == NULL)
// 	{
// 		*alst = newlist;
// 		newlist->next = NULL;
// 	}
// 	else
// 		ft_lstlast(*alst)->next = newlist;
// }

HRESULT		gmx_add_fragshader(
	t_vec (*frag_out)(const t_fragment))
{
	t_shadersrc	**last;

	last = &gmx_global(NULL)->shaders;
	
	while (*last)
		*last = (*last)->next;
	*last = (t_shadersrc *)ft_calloc(1, sizeof(t_shadersrc));
	if (*last == NULL)
		return (GMX_MEMERR);
	(*last)->frag_out = frag_out;
	return (GMX_SUCCESS);
}
