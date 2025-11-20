/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.4-parser_obj_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:55:35 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 18:14:31 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_get_obj(t_obj_type type, char *line)
{
	if (type == SPHERE)
		return (ft_parser_sphere(line));
	if (type == PLANE)
		return (ft_parser_plane(line));
	if (type == CYLINDER)
		return (ft_parser_cylinder(line));
	return (NULL);
}
