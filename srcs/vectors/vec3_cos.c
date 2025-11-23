/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:58:24 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/11/23 19:17:26 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double  vec3_cos(t_vec3 vec1, t_vec3 vec2)
{
    double  dot;
    double  len;

    dot = vec3_dot(vec1, vec2);
    len = vec3_len(vec1) * vec3_len(vec2);
    return (dot / len);
}
