/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_arrange.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 10:34:45 by goosterl      #+#    #+#                 */
/*   Updated: 2021/12/10 11:22:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <libft.h>
#include <stdio.h>

/*
**	Re-order vector
**	Input must be at least one character and at most four characters
**	Characters to be used are: X, Y, Z, W
**	Ex: "XXYZ", "YYYY"
*/
t_vec	arrange(const t_vec v1, const char *order)
{
	char		current;
	t_vec		outvec;
	uint32_t	idx;
	size_t		len;
	
	len = ft_strlen(order);
	if (len < 1 || len > 4)
	{
		perror("Vec: Order\n - *order length is invalid\n");
		return (v1);
	}
	idx = 0;
	while (order[idx] != '\0')
	{
		current = ft_toupper(order[idx]);
		if (current != 'X' && current != 'Y' && current != 'Z' && current != 'W')
		{
			perror("Invalid vector component\n");
			return (v1);
		}
		outvec[idx] = v1[(current - (88 - 4)) % 4];
	}
	return (outvec);
}
