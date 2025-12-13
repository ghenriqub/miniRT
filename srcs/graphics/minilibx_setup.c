/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:33:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/13 21:16:51 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_graphics(t_scene *scene)
{
	scene->disp.mlx = mlx_init();
	if (!scene->disp.mlx)
		ft_exit("Error: MLX initialization failed", 1);
	scene->disp.win = mlx_new_window(scene->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!scene->disp.win)
		ft_exit("Error: Window creation failed", 1);
	scene->disp.img = mlx_new_image(scene->disp.mlx, WIDTH, HEIGHT);
	if (!scene->disp.img)
		ft_exit("Error: Image creation failed", 1);
	scene->disp.addr = mlx_get_data_addr(scene->disp.img, &scene->disp.bpp,
			&scene->disp.line_length, &scene->disp.endian);
	if (!scene->disp.addr)
		ft_exit("Error: Image address failed", 1);
}
