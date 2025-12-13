/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:39:35 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/13 15:02:45 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_objects(t_scene *scene, t_ray ray, t_hit *hit)
{
	double		t;
	int			i;
	t_object	*obj;

	hit->t = INFINITY;
	hit->object = NULL;
	hit->type = INVALID;
	i = 0;
	while (i < scene->object_count)
	{
		obj = scene->objects[i];
		if (obj->type == SPHERE)
		{
			if (hit_sphere(ray, (t_sphere *)obj->data, &t))
			{
				if (t > 1e-6 && t < hit->t)
				{
					hit->t = t;
					hit->object = obj->data;
					hit->type = SPHERE;
				}
			}
		}
		else if (obj->type == PLANE)
		{
			if (hit_plane(ray, (t_plane *)obj->data, &t))
			{
				if (t > 1e-6 && t < hit->t)
				{
					hit->t = t;
					hit->object = obj->data;
					hit->type = PLANE;
				}
			}
		}
		else if (obj->type == CYLINDER)
		{
			if (hit_cylinder(ray, (t_cylinder *)obj->data, &t))
			{
				if (t > 1e-6 && t < hit->t)
				{
					hit->t = t;
					hit->object = obj->data;
					hit->type = CYLINDER;
				}
			}
		}
		i++;
	}
	return (hit->object != NULL);
}
