/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:28:43 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/17 13:44:19 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec3	vec3_reflect(t_vec3 dir, t_vec3 normal)
{
	return (vec3_sub(dir,
			vec3_scale(normal, 2.0 * vec3_dot(dir, normal))));
}
