/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:38:39 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 16:32:26 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*ft_parser(t_args *args)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	scene->light_count = args->light_count;
	scene->object_count = args->obj_count;
	scene->ambient = ft_parser_al(args->ambient_light);
	scene->camera = ft_parser_c(args->camera);
	scene->light = ft_parser_l(args->light);
	scene->objects = ft_parser_ob(args->objects);
	if (scene->ambient_light == NULL || scene->camera == NULL
		|| (scene->light_count > 0 && scene->light == NULL)
		|| (scene->objects[0] == NULL))
	{
		ft_free_args(args);
		ft_free_scene(scene);
		ft_exit(ERROR_SCENE, 2);
	}
}

// 1 - count parts to verified if have 3 arguments.
// 2 - if with 3 condictions:
//		first argument is 'A'.
//			parser ratio, if arguments is a float 0.0 - 1.0.
//				parser RGB xxx,xxx,xxx.
// 3 - strdup and get rgb for allocate arguments.
t_ambient_light	*ft_parser_al(char *input)
{
	t_ambient	*al;
	char		**args;

	if (count_parts(input, ' ') != 3)
		return (NULL);
	args = ft_split(input, ' ');
	if (strncmp(args[0], "A", strlen(args[0])) != 0
		|| !ft_parser_ratio(args[1], 0.0, 1.0)
		|| !ft_parser_rgb(args[2]))
	{
		ft_free_split(args);
		return (NULL);
	}
	al = ft_calloc(sizeof(t_ambient), 1);
	al->ratio = ft_atof(args[1]);
	al->color = ft_get_rgb(args[2]);
	ft_free_split(args);
	return (al);
}

t_camera	*ft_parser_c(char *input)
{
	t_camera	*camera;
	char		**args;

	if (count_parts(input, ' ') != 4)
		return (NULL);
	args = ft_split(input, ' ');
	if (strncmp(args[0], "C", strlen(args[0])) != 0
		|| !ft_parse_vec3(args[1])
		|| !ft_parser_normalized(args[2])
		|| !ft_parse_fov(args[3]))
	{
		ft_free_split(args);
		return (NULL);
	}
	camera = ft_calloc(sizeof(t_camera), 1);
	camera->position = ft_get_vec3(args[1]);
	camera->vector = ft_get_vec3(args[2]);
	camera->fov = atof(args[3]);
	return (camera);
}

t_light	**ft_parser_l(char **input, int count_light)
{
	t_light	**light;
	char	**args;
	int		i;

	i = 0;
	light = ft_alloc_arraystruc(count_light, sizeof(t_light));
	if (!lights)
		return (NULL);
	while (input[i++])
	{
		if (count_parts(input[i], ' ') != 4)
			return (ft_free_light(light), NULL);
		args = ft_split(input[i], ' ');
		if (strncmp(args[0], "L", strlen(args[0])) != 0
			|| !ft_parse_vec3(args[1])
			|| !ft_parser_ratio(args[2], 0, 1)
			|| !ft_parset_rgb(args[3]))
			return (ft_free_arraystruc(light, count_light),
				ft_free_split(args), NULL);
		light[i]->position = ft_get_vec3(args[1]);
		light[i]->ratio = ft_atof(args[2]);
		light[i]->color = ft_get_rgb(args[3]);
		ft_free_split(args);
	}
	return (light);
}
