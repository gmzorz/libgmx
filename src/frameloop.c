/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frameloop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 13:52:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 16:40:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

static t_vec	get_sampled_aa_color(
	t_vec (*frag_out)(const t_fragment),
	t_fragment frag,
	int32_t *pos)
{
	t_vec		accum;
	int32_t		idx;
	int32_t		p[8];

	idx = 0;
	p[0] = pos[X] * 2;
	p[1] = pos[Y] * 2;
	p[2] = p[0];
	p[3] = p[1] + 1;
	p[4] = p[0] + 1;
	p[5] = p[1];
	p[6] = p[0] + 1;
	p[7] = p[1] + 1;
	accum = vec(0.f);
	while (idx < 4)
	{
		frag.coord = vec2(
			(float)p[idx * 2] / frag.width2 - 0.5f,
			(float)p[idx * 2 + 1] / frag.height2 - 0.5f);
		accum += frag_out(frag);
		idx += 1;
	}
	return (accum * 0.25f);
}

static void	gmx_aa_frameloop(
	t_gmx *user,
	t_vec (*frag_out)(const t_fragment),
	t_fragment frag)
{
	int32_t		framepos;
	int32_t		pos[2];

	ft_memset(pos, 0, 8);
	while (pos[Y] < user->image.height)
	{
		while (pos[X] < user->image.width)
		{
			framepos = user->image.width * pos[Y] + pos[X];
			frag.color = user->framebuffer[framepos];
			user->framebuffer[framepos] = get_sampled_aa_color(
				frag_out, frag, pos);
			pos[X] += 1;
		}
		pos[X] = 0;
		pos[Y] += 1;
	}
}

void	gmx_frameloop(
	t_gmx *user,
	t_vec (*frag_out)(const t_fragment),
	t_fragment frag)
{
	int32_t		framepos;
	int32_t		pos[2];

	if (user->anti_alias == true)
		return (gmx_aa_frameloop(user, frag_out, frag));
	ft_memset(pos, 0, 8);
	while (pos[Y] < user->image.height)
	{
		while (pos[X] < user->image.width)
		{
			framepos = user->image.width * pos[Y] + pos[X];
			frag.coord = vec2(
				(float)pos[X] / frag.width - 0.5f,
				(float)pos[Y] / frag.height - 0.5f);
			frag.color = user->framebuffer[framepos];
			user->framebuffer[framepos] = frag_out(frag);
			pos[X] += 1;
		}
		pos[X] = 0;
		pos[Y] += 1;
	}
}
