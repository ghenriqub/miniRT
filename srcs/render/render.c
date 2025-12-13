/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:48:20 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/12/13 20:05:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    render_scene(t_scene *scene)
{
    int     x;
    int     y;
    t_ray   ray;
    t_hit   hit;
    t_rgb   color;
    t_vec3  point;
    t_vec3  normal;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            ray = make_ray(x, y, scene);
            if (hit_objects(scene, ray, &hit))
            {
				point = vec3_add(ray.origin, vec3_scale(ray.direction, hit.t));
				normal = get_normal(&hit, point);
				color = shade_hit(scene, &hit, point, normal);
            }
			else
				color = (t_rgb){0, 0, 0};
			put_pixel(scene, x, y, rgb_to_int(color));
			x++;
		}
		y++;
    }
	mlx_put_image_to_window(scene->disp.mlx, scene->disp.win,
				scene->disp.img, 0, 0);
}

void	put_pixel(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	
	dst = scene->disp.addr + (y * scene->disp.line_length 
							+ x * (scene->disp.bpp / 8));
	*(unsigned int *)dst = color;
}
