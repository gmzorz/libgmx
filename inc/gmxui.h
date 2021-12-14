/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gmxui.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 14:53:39 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:43:52 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMXUI_H
# define GMXUI_H
# include <libft.h>
# include <mlx.h>
# include <stdint.h>
# include <vec.h>
# include <xevent.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <gmmath.h>
# define HRESULT		int
# define GMX_NODEVICE	-1
# define GMX_SUCCESS	1
# define GMX_FAILURE	0
# define GMX_MEMERR		2

typedef void *		t_instance;
typedef int8_t *	t_bitmap;
typedef t_vec *		t_framebuffer;
typedef void *		t_pointer;
typedef char		t_byte;

/*
**	Pixel format
*/
typedef enum e_pixfmt
{
	GMFMT_R8G8B8		= 24,
	GMFMT_R8G8B8A8		= 32,
	GMFMT_R32G32B32		= 96,
	GMFMT_R32G32B32A32	= 138
}	t_pixfmt;

typedef struct s_buffer
{
	t_vec			*texbuffer;
	char			*tag;
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_image
{
	t_instance		object;
	t_bitmap		address;
	int32_t			width;
	int32_t			height;
	t_pixfmt		bpp;
	int32_t			pitch;
	int32_t			endian;
	t_buffer		*buffer_entry;
	struct s_image	*next;
}	t_image;

typedef struct s_fragment
{
	t_vec			coord;
	t_vec			color;
	float			width;
	float			height;
	float			time;
	void			*geometry;
	HRESULT			(*sampler)(const char *, int32_t, int32_t);
}	t_fragment;

typedef struct s_shadersrc
{
	t_vec				(*frag_out)(const t_fragment);
	struct s_shadersrc	*next;
}	t_shadersrc;

typedef struct s_geosrc
{
	void			*geo;
	struct s_geosrc	*next;
}	t_geosrc;

typedef struct s_gmx
{
	t_instance		object;
	t_instance		window;
	t_image			image;
	t_framebuffer	framebuffer;
	t_shadersrc		*shaders;
	t_image			*buffers;
	t_geosrc		*geometry;
}	t_gmx;

HRESULT		gmx_init(
				const int32_t width,
				const int32_t height,
				const char *title);

HRESULT		*gmx_new_buffer(
				const int32_t width,
				const int32_t height,
				const char *tag);

HRESULT		gmx_push_key_hook(
				const t_keybutton button,
				bool (*funct_ptr)(),
				void *args);

HRESULT		gmx_push_mouse_hook(
				const t_mousebutton button,
				bool (*funct_ptr)(),
				void *args);

HRESULT		gmx_execconfig(
				const char *file);

HRESULT		gmx_render(void);

HRESULT		gmx_start(void);

HRESULT		gmx_add_fragshader(
				t_vec (*frag_out)(const t_fragment));

HRESULT		gmx_add_geometry(
				void *geometry);

t_gmx		*gmx_global(t_gmx *init);

#endif
