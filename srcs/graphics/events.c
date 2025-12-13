/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:42:38 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/13 21:16:52 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_window(t_scene *scene)
{
	if (!scene)
		exit(0);
	if (scene->disp.img)
		mlx_destroy_image(scene->disp.mlx, scene->disp.img);
	if (scene->disp.win)
		mlx_destroy_window(scene->disp.mlx, scene->disp.win);
	ft_free_scene(scene);
	mlx_destroy_display(scene->disp.mlx);
	free(scene->disp.mlx);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_scene *scene)
{
	if (keycode == 65307)
		close_window(scene);
	return (0);
}
