/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:14 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/14 13:35:42 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*this file have free functions.*/

void	ft_free_arraystruc(void **arr, int count)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < count)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_scene(t_scene *scene)
{
	int	i;

	if (!scene)
		return ;
	if (scene->ambient)
		free(scene->ambient);
	if (scene->camera)
		free(scene->camera);
	if (scene->lights)
	{
		i = 0;
		while (i < scene->light_count)
		{
			if (scene->lights[i])
				free(scene->lights[i]);
			i++;
		}
		free(scene->lights);
	}
	if (scene->objects)
		ft_free_objects_struc(scene->objects, scene->object_count);
	free(scene);
}

void	ft_free_object(t_object *obj)
{
	if (!obj)
		return ;
	if (obj->data)
	{
		if (obj->type == SPHERE)
			free((t_sphere *)obj->data);
		else if (obj->type == PLANE)
			free((t_plane *)obj->data);
		else if (obj->type == CYLINDER)
			free((t_cylinder *)obj->data);
	}
	free(obj);
}

void	ft_free_objects_struc(t_object **arr, int count)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < count)
	{
		if (arr[i])
			ft_free_object(arr[i]);
		i++;
	}
	free(arr);
}
