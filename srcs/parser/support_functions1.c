/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:14 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/21 21:49:05 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_arraystruc(void **arr, int count)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < count)
	{
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
	free(scene->ambient);
	free(scene->camera);
	if (scene->lights)
	{
		i = -1;
		while (scene->lights[++i])
			free(scene->lights[i]);
		free(scene->lights);
	}
	if (scene->objects)
		ft_free_objects_struc(scene->objects, scene->object_count);
	free(scene);
}

void	ft_free_objectt(t_object *obj)
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
		ft_free_objectt(arr[i]);
		i++;
	}
	free(arr);
}
