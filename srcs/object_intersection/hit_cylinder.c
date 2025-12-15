/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:45:05 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/15 17:27:51 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define EPSILON 1e-6
#define INF_VAL 1e30

static bool	cy_lateral(t_ray ray, t_cylinder *cy, double *out);
static bool	cy_cap(t_ray ray, t_cylinder *cy, double *out, int top);

bool	hit_cylinder(t_ray ray, t_cylinder *cy, double *t)
{
	double	t_lateral;
	double	t_top;
	double	t_bottom;
	bool	hit;

	t_lateral = INF_VAL;
	t_top = INF_VAL;
	t_bottom = INF_VAL;
	hit = false;
	if (cy_lateral(ray, cy, &t_lateral))
		hit = true;
	if (cy_cap(ray, cy, &t_top, 1))
		hit = true;
	if (cy_cap(ray, cy, &t_bottom, 0))
		hit = true;
	if (!hit)
		return (false);
	*t = t_lateral;
	if (t_top < *t && t_top > EPSILON)
		*t = t_top;
	if (t_bottom < *t && t_bottom > EPSILON)
		*t = t_bottom;
	return (true);
}

/*
 * caps: top == 1 -> top cap ; top == 0 -> bottom cap
 * assume cy->center is the base (bottom).
 * top center = center + normal*height
 */
static bool	cy_cap(t_ray ray, t_cylinder *cy, double *out, int top)
{
	t_plane	pl;
	t_vec3	center;
	t_vec3	p;
	double	t;

	if (top)
		center = vec3_add(cy->center, vec3_scale(cy->normal, cy->height));
	else
		center = cy->center;
	pl.point = center;
	pl.normal = cy->normal;
	pl.color = (t_rgb){0, 0, 0};
	if (!hit_plane(ray, &pl, &t))
		return (false);
	if (t < EPSILON)
		return (false);
	p = vec3_add(ray.origin, vec3_scale(ray.direction, t));
	if (vec3_len(vec3_sub(p, center)) <= cy->diameter / 2.0)
	{
		*out = t;
		return (true);
	}
	return (false);
}

// a = 
static bool	cy_lateral(t_ray ray, t_cylinder *cy, double *out)
{
	t_vec3	oc;
	t_vec3	d;
	t_vec3	w;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
	t_vec3	p;
	double	h;

	oc = vec3_sub(ray.origin, cy->center);
	d = vec3_sub(ray.direction,
			vec3_scale(cy->normal, vec3_dot(ray.direction, cy->normal)));
	w = vec3_sub(oc, vec3_scale(cy->normal, vec3_dot(oc, cy->normal)));
	a = vec3_dot(d, d);
	b = 2 * vec3_dot(d, w);
	c = vec3_dot(w, w) - (cy->diameter * cy->diameter) / 4.0;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0 || fabs(a) < EPSILON)
		return (false);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 > EPSILON)
	{
		p = vec3_add(ray.origin, vec3_scale(ray.direction, t1));
		h = vec3_dot(vec3_sub(p, cy->center), cy->normal);
		if (h >= 0.0 && h <= cy->height)
		{
			*out = t1;
			return (true);
		}
	}
	if (t2 > EPSILON)
	{
		p = vec3_add(ray.origin, vec3_scale(ray.direction, t2));
		h = vec3_dot(vec3_sub(p, cy->center), cy->normal);
		if (h >= 0.0 && h <= cy->height)
		{
			*out = t2;
			return (true);
		}
	}
	return (false);
}
