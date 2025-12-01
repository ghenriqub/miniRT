/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:33:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/01 19:46:59 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_graphics(t_scene *scene)
{
	scene->disp.mlx = mlx_init();
	if (!scene->disp.mlx)
		return (1);
	scene->disp.win = mlx_new_window(scene->disp.mlx, WIDTH, HEIGHT, "minirt");
	if (!scene->disp.win)
		return (1);
	scene->disp.img = mlx_new_image(scene->disp.mlx, WIDTH, HEIGHT);
	if (!scene->disp.img)
		return (1);
	scene->disp.addr = mlw_get_data_addr(scene->disp.img, &scene->disp.bpp, \
		&scene->disp.line_length, &scene->disp.endian);
	if (!scene->disp.addr)
		return (1);
}
