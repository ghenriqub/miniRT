/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:45:05 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/08 16:03:10 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		cy_prep(t_cycalc *s, t_ray ray, t_cylinder *cy);
static int		cy_height_check(t_ray ray, t_cylinder *cy, double t);
static double	cy_solve(t_cycalc *s, t_ray ray, t_cylinder *cy);

double	hit_cylinder(t_ray ray, t_cylinder *cy)
{
	t_cycalc	s;

	cy_prep(&s, ray, cy);
	return (cy_solve(&s, ray, cy));
}

static double	cy_solve(t_cycalc *s, t_ray ray, t_cylinder *cy)
{
	double	t1;
	double	t2;

	if (s->discr < 0)
		return (-1);
	t1 = (-s->b - sqrt(s->discr)) / (2 * s->a);
	t2 = (-s->b + sqrt(s->discr)) / (2 * s->a);
	if (cy_height_check(ray, cy, t1))
		return (t1);
	if (cy_height_check(ray, cy, t2))
		return (t2);
	return (-1);
}

static int	cy_height_check(t_ray ray, t_cylinder *cy, double t)
{
	t_vec3	p;
	double	h;

	if (t < 0)
		return (0);
	p = vec3_add(ray.origin, vec3_scale(ray.direction, t));
	h = vec3_dot(vec3_sub(p, cy->center), cy->normal);
	return (h >= 0 && h <= cy->height);
}

static void	cy_prep(t_cycalc *s, t_ray ray, t_cylinder *cy)
{
	s->oc = vec3_sub(ray.origin, cy->center);
	s->n = cy->normal;
	s->d = vec3_sub(ray.direction,
			vec3_scale(s->n, vec3_dot(ray.direction, s->n)));
	s->oc = vec3_sub(s->oc,
			vec3_scale(s->n, vec3_dot(s->oc, s->n)));
	s->a = vec3_dot(s->d, s->d);
	s->b = 2 * vec3_dot(s->d, s->oc);
	s->c = vec3_dot(s->oc, s->oc) - (cy->diameter * cy->diameter) / 4.0;
	s->discr = s->b * s->b - 4 * s->a * s->c;
}
