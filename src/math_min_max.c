/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_min_max.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 12:24:44 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 12:26:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float	min(const float v1, const float v2)
{
	if (v2 < v1)
		return (v2);
	return (v1);
}

float	max(const float v1, const float v2)
{
	if (v2 > v1)
		return (v2);
	return (v1);
}
