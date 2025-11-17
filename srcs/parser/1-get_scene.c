/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-get_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:41 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/17 16:18:04 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_args	*ft_get_scene(char *file)
{
	t_args	*args;

	args = ft_allocate_scene(file);
	return (args);
}
