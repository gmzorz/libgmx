/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 12:22:02 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/15 13:29:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gmxui.h>
#include <xevent.h>

static int	look_handle(
	int32_t x,
	int32_t y,
	void (*function)(int32_t dx, int32_t dy))
{
	int32_t	center[2];
	
	center[X] = gmx_global(NULL)->image.width / 2;
	center[Y] = gmx_global(NULL)->image.height / 2;
	
	if (gmx_global(NULL)->mflags = 
}

void	gmx_mouse_motion(void (*function)(int32_t dx, int32_t dy))
{
	t_gmx	*user;

	user = gmx_global(NULL);
	mlx_hook(user->window, MOTION, MASK_BUTTON, look_handle, function);
}