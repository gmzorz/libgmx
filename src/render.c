/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:07:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 16:41:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>
#include "global.h"

static uint32_t	compress_color(t_vec color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = (float)(color[X]);
	g = (float)(color[Y]);
	b = (float)(color[Z]);
	return (b | g << 8 | r << 16);
}

static void	gmx_present(t_gmx *user)
{
	t_vec		color;
	uint32_t	pixel_color;
	int32_t		pos[2];
	uint32_t	pixel_pos;
	uint32_t	frame_pos;

	ft_memset(pos, 0, 8);
	while (pos[Y] < user->image.height)
	{
		while (pos[X] < user->image.width)
		{
			pixel_pos = (pos[Y] * user->image.pitch
					+ pos[X] * (user->image.bpp / 8));
			frame_pos = pos[Y] * user->image.width + pos[X];
			color = saturate(user->framebuffer[frame_pos]) * 255.f;
			pixel_color = compress_color(color);
			*(uint32_t *)(user->image.address + pixel_pos) = pixel_color;
			pos[X] += 1;
		}
		pos[X] = 0;
		pos[Y] += 1;
	}
}

HRESULT	gmx_render(void)
{
	t_gmx		*user;
	t_shadersrc	*shaders;
	t_fragment	frag;

	user = gmx_global(NULL);
	shaders = user->shaders;
	while (shaders)
	{
		frag.height = user->image.height;
		frag.width = user->image.width;
		frag.height2 = frag.height * 2.f;
		frag.width2 = frag.width * 2.f;
		gmx_frameloop(user, shaders->frag_out, frag);
		shaders = shaders->next;
	}
	gmx_present(user);
	return (GMX_SUCCESS);
}
