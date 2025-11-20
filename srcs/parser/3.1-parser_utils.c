/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1-parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:20:22 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 15:06:02 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_is_number(char *str)
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
	float	value;

	if (!ft_float_format(str))
		return (0);
	value = ft_atof(str);
	if (value < min || value > max)
		return (0);
	return (1);
}

int	ft_parse_vec3(char *str)
{
	char	**p;

	p = ft_split(str, ',');
	if (!p || ft_split_count(p) != 3)
		return (ft_free_split(p), 0);
	if (!ft_float_format(p[0])
		|| !ft_float_format(p[1])
		|| !ft_float_format(p[2]))
		return (ft_free_split(p), 0);
	ft_free_split(p);
	return (1);
}

int	ft_is_normalized(char *str)
{
	char	**args;

	if (!ft_parser_vec3(str))
		return (0);
	args = split(str);
	if (ft_parser_ratio(str[0], -1, 1)
		|| ft_parser_ratio(str[1], -1, 1)
		|| ft_parser_ratio(str[2], -1, 1))
	{
		ft_free_split(args);
		return (0);
	}
	ft_free_split(args);
	return (1);
}
