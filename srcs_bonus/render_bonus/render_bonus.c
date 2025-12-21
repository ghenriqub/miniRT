/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:48:20 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/17 16:20:19 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#define DEPTH 3
#define TEST_REFLECTIVITY 0.5

/*
typedef struct s_render_st
{
	t_vec3	point;
	t_vec3	normal;
	t_rgb	local_color;
	t_rgb	reflected_color;
	t_ray	rd.reflected_ray;
}	t_render_st;
*/

t_rgb	compute_pixel_color(t_scene *scene, t_ray ray, int depth)
{
	t_hit		hit;
	t_render_st	rd;
	double		r;

	if (depth <= 0 || !hit_objects(scene, ray, &hit))
		return ((t_rgb){0, 0, 0});
	rd.point = vec3_add(ray.origin, vec3_scale(ray.direction, hit.t));
	rd.normal = get_normal(&hit, rd.point);
	rd.local_color = shade_hit(scene, &hit, rd.point, rd.normal);
	r = get_reflectivity(&hit);
	if (r <= 0.0)
		return (rd.local_color);
	rd.reflected_ray.origin = vec3_add(rd.point,
			vec3_scale(rd.normal, 1e-4));
	rd.reflected_ray.direction = vec3_normalize(
			vec3_reflect(ray.direction, rd.normal));
	rd.reflected_color = compute_pixel_color(scene,
			rd.reflected_ray, depth - 1);
	return (rgb_clamp(rgb_add(
				vec3_rgb_scale(rd.local_color, 1.0 - r),
				vec3_rgb_scale(rd.reflected_color, r)
			)));
}

static void	render_row(t_scene *scene, int y)
{
	int		x;
	t_rgb	color;

	x = 0;
	while (x < WIDTH)
	{
		color = compute_pixel_color(scene, make_ray(x, y, scene), DEPTH);
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
