/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:14 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/21 20:44:33 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_arraystruc(void **arr, int count)
{
	int	i;

	(void)count;
	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	ft_free_object(t_object *obj)
{
	if (!obj)
		return ;
	if (obj->data)
		free(obj->data);
}

void	ft_free_objects(t_object **objs)
{
	int	i;

	i = 0;
	if (!objs)
		return ;
	while (objs[i])
	{
		ft_free_object(objs[i]);
		free(objs[i]);
		i++;
	}
	free(objs);
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
	{
		i = -1;
		while (scene->objects[++i])
		{
			if (scene->objects[i]->data)
				free(scene->objects[i]->data);
			free(scene->objects[i]);
		}
		free(scene->objects);
	}
	free(scene);
}
