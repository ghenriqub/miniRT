/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2-parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:13:09 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 16:30:39 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_fov(char *str)
{
	float	fov;

	if (!ft_is_number(str))
		return (0);
	fov = ft_atof(str);
	if (fov < 0 || fov > 180)
		return (0);
	return (1);
}

static int	ft_float_format_util(const char *str)
{
	int	i;
	int	digits;
	int	dots;

	i = 0;
	digits = 0;
	dots = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digits++;
		else if (str[i] == '.')
			if (++dots > 1)
				return (0);
		else
			return (0);
		i++;
	}
	return (digits > 0);
}

int	ft_float_format(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	return (ft_float_format_util(&str[i]));
}

void	**ft_alloc_arraystruc(int count, size_t type_size)
{
	int		i;
	int		k;
	void	**arr;

	arr = ft_calloc(count, sizeof(void *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = ft_calloc(1, type_size);
		if (!arr[i])
		{
			k = 0;
			while (k++ < i)
				free(arr[k]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
