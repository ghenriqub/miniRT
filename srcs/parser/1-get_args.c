/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-get_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:41 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/18 15:39:00 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_args	*ft_get_args(char *file)
{
	t_args	*args;

	args = ft_allocate_args(file);
	return (args);
}
