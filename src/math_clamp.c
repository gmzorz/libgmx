/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_clamp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 13:38:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 13:39:04 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float	clampf(const float num, const float min, const float max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}
