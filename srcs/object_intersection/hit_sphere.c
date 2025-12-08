/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:36:51 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/08 16:47:33 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sphere(t_ray ray, t_sphere *sp, double *t)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	sqrt_d;
	double	t0;
	double	t1;

	oc = vec3_sub(ray.origin, sp->center);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2.0 * vec3_dot(oc, ray.direction);
	c = vec3_dot(oc, oc) - (sp->diameter / 2) * (sp->diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	sqrt_d = sqrt(delta);
	t0 = (-b - sqrt_d) / (2 * a);
	t1 = (-b + sqrt_d) / (2 * a);
	if (t0 > 1e-6)
	{
		*t = t0;
		return (true);
	}
	if (t1 > 1e-6)
	{
		*t = t1;
		return (true);
	}
	return (false);
}
