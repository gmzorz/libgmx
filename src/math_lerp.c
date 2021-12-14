/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_lerp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 14:03:50 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 14:04:46 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float	lerp(const float v0, const float v1, const float t)
{
	return ((1 - t) * v0 + t * v1);
}
