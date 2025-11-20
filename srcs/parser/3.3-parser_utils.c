/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3-parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:02:49 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 15:05:36 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	ft_get_rgb(char *str)
{
	t_rgb	rgb;
	char	**vals;

	vals = ft_split(str, ',');
	if (!vals || ft_split_count(vals) != 3)
	{
		ft_free_split(vals);
		ft_exit(ERROR_RGB, 2);
	}
	rgb.r = ft_atoi(vals[0]);
	rgb.g = ft_atoi(vals[1]);
	rgb.b = ft_atoi(vals[2]);
	ft_free_split(vals);
	return (rgb);
}

static void	ft_atof_decimal_part(const char *str, int *i, float *result)
{
	float	decimal;

	decimal = 0.1f;
	if (str[*i] != '.')
		return ;
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result += (str[*i] - '0') * decimal;
		decimal *= 0.1f;
		(*i)++;
	}
}

float	ft_atof(const char *str)
{
	int		i;
	int		sign;
	float	result;

	i = 0;
	sign = 1;
	result = 0.0f;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0f + (str[i] - '0');
		i++;
	}
	ft_atof_decimal_part(str, &i, &result);
	return (result * sign);
}

t_vec3	ft_get_vec3(char *str)
{
	t_vec3	v;
	char	**parts;

	parts = ft_split(str, ',');
	v.x = ft_atof(parts[0]);
	v.y = ft_atof(parts[1]);
	v.z = ft_atof(parts[2]);
	ft_free_split(parts);
	return (v);
}
