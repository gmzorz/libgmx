/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gmx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:42:28 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/09 16:58:58 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>

HRESULT	gmx_start(void)
{
	t_gmx	*user;

	user = gmx_global(NULL);
	if (user == NULL)
	{
		perror("Device not present\n");
		return (GMX_NODEVICE);
	}
	mlx_put_image_to_window(
		user->object, user->window, user->image.object, 0, 0);
	mlx_loop(user->object);
	return (GMX_SUCCESS);
}

void	flush_framebuffer(t_vec **framebuffer, int32_t sizex, int32_t sizey)
{
	uint32_t	idx;
	uint32_t	max;

	idx = 0;
	max = sizex * sizey;
	while (idx < max)
	{
		(*framebuffer)[idx] = (t_vec){0.0f, 0.0f, 0.0f, INFINITY};
		idx += 1;
	}
}

HRESULT	gmx_init(
	const int32_t width,
	const int32_t height,
	const char *title)
{
	t_gmx	*new;

	new = (t_gmx *)ft_calloc(1, sizeof(t_gmx));
	if (new == NULL)
	{
		perror("Failed to initialize mlx wrapper\n");
		return (GMX_MEMERR);
	}
	gmx_global(new);
	new->object = mlx_init();
	new->window = mlx_new_window(new->object, width, height, (char *)title);
	new->image.object = mlx_new_image(new->object, width, height);
	new->image.address = (t_bitmap)mlx_get_data_addr(new->image.object,
			(int *)&new->image.bpp, &new->image.pitch, &new->image.endian);
	new->image.width = width;
	new->image.height = height;
	new->framebuffer = (t_framebuffer)ft_calloc(1, sizeof(t_vec)\
		* new->image.width * new->image.height);
	if (new->framebuffer == NULL)
	{
		perror("Failed to initialize framebuffer\n");
		return (GMX_MEMERR);
	}
	flush_framebuffer(&new->framebuffer, new->image.width, new->image.height);
	return (GMX_SUCCESS);
}
