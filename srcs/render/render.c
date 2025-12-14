/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:48:20 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/14 18:28:51 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	compute_pixel_color(t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_hit	hit;
	t_vec3	point;
	t_vec3	normal;

	ray = make_ray(x, y, scene);
	if (!hit_objects(scene, ray, &hit))
		return ((t_rgb){0, 0, 0});
	point = vec3_add(ray.origin, vec3_scale(ray.direction, hit.t));
	normal = get_normal(&hit, point);
	return (shade_hit(scene, &hit, point, normal));
}

static void	render_row(t_scene *scene, int y)
{
	int		x;
	t_rgb	color;

	x = 0;
	while (x < WIDTH)
	{
		color = compute_pixel_color(scene, x, y);
		put_pixel(scene, x, y, rgb_to_int(color));
		x++;
	}
}

static void	display_image(t_scene *scene)
{
	if (scene->disp.mlx && scene->disp.win && scene->disp.img)
		mlx_put_image_to_window(scene->disp.mlx,
			scene->disp.win, scene->disp.img, 0, 0);
}

void	render_scene(t_scene *scene)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(scene, y);
		y++;
	}
	display_image(scene);
}

void	put_pixel(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = scene->disp.addr + (y * scene->disp.line_length
			+ x * (scene->disp.bpp / 8));
	*(unsigned int *)dst = color;
}
