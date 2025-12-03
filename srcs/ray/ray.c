/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:41:55 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/03 15:50:45 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_vec3 o, t_vec3 d)
{
	t_ray	r;

	r.origin = o;
	r.direction = vec3_normalize(d);
	return (r);
}
