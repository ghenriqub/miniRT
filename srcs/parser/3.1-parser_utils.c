/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1-parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:20:22 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/19 17:29:40 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parser_rgb(char *str)
{
	char	**s;
	int		i;
	int		value;

	s = ft_split(str, ',');
	if (!s || ft_split_count(s) != 3)
		return (ft_free_split(s), 0);
	i = -1;
	while (++i < 3)
	{
		if (!ft_is_number(s[i]))
			return (ft_free_split(s), 0);
		value = ft_atoi(s[i]);
		if (value < 0 || value > 255)
			return (ft_free_split(s), 0);
	}
	ft_free_split(s);
	return (1);
}

int	ft_parser_ratio(char *str, float min, float max)
{
	int		i;
	int		dot_count;
	float	value;

	if (!str || !*str)
		return (0);
	i = 0;
	dot_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		if (dot_count > 1)
			return (0);
		i++;
	}
	value = atof(str);
	if (value < min || value > max)
		return (0);
	return (1);
}
