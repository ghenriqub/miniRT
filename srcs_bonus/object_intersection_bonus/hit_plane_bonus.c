/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:42:52 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/13 15:09:54 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

bool	hit_plane(t_ray ray, t_plane *pl, double *t)
{
	double	denom;
	t_vec3	p0l0;
	double	temp_t;

	denom = vec3_dot(pl->normal, ray.direction);
	if (fabs(denom) < 1e-6)
		return (false);
	p0l0 = vec3_sub(pl->point, ray.origin);
	temp_t = vec3_dot(p0l0, pl->normal) / denom;
	if (temp_t < 1e-6)
		return (false);
	*t = temp_t;
	return (true);
}
