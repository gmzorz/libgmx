/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frameloop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 13:52:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:25:06 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

static void	gmx_fragloop(
	t_gmx *user,
	t_fragment frag,
	t_vec (*frag_out)(const t_fragment),
	int32_t framepos)
{
	t_vec		fragcol;
	t_vec		bufcol;
	t_geosrc	*geometry;

	geometry = user->geometry;
	bufcol = user->framebuffer[framepos];
	if (geometry == NULL)
	{
		fragcol = frag_out(frag);
		if (fragcol[W] < bufcol[W])
			bufcol = fragcol;
	}
	while (geometry)
	{
		frag.geometry = geometry->geo;
		fragcol = frag_out(frag);
		bufcol = user->framebuffer[framepos];
		if (fragcol[W] < bufcol[W])
			bufcol = fragcol;
		geometry = geometry->next;
	}
	user->framebuffer[framepos] = bufcol;
}

static void	gmx_frameloop(
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
			frag.coord[0] = (float)pos[X] / (float)frag.width * 2.f - 1.f;
			frag.coord[1] = (float)pos[Y] / (float)frag.height * 2.f - 1.f;
			frag.coord[2] = 0.f;
			frag.coord[3] = 0.f;
			frag.color = user->framebuffer[framepos];
			gmx_fragloop(user, frag, frag_out, framepos);
			pos[X] += 1;
		}
		pos[X] = 0;
		pos[Y] += 1;
	}
}

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
		gmx_frameloop(user, shaders->frag_out, frag);
		shaders = shaders->next;
	}
	gmx_present(user);
	return (GMX_SUCCESS);
}
