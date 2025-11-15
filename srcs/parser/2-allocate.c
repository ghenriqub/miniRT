/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-allocate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:08:27 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/15 16:05:16 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_is_object(char *line)
{
	if (!line || !*line)
		return (0);
	if (line[0] == '#' || line[0] == '\n' || line[0] == '\0'
		|| line[0] == 'A' || line[0] == 'C' || line[0] == 'L')
		return (0);
	return (1);
}

static int	ft_obj_count(char *file)
{
	char	*line;
	int		fd;
	int		obj_count;

	obj_count = 0;
	fd = ft_get_fd(file);
	line = get_next_line(fd);
	if (!line || !line[0])
	{
		close(fd);
		exit(0);
	}
	while (line)
	{
		if (ft_is_object(line))
			obj_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (obj_count);
}

static char	*ft_is_double(t_scene *scene, char *target, char *line, int fd)
{
	if (target)
	{
		free(line);
		ft_free_scene(scene);
		close(fd);
		ft_exit(ERROR_SCENE, 2);
	}
	return (ft_strdup(line));
}

void	ft_put_argument(t_scene *scene, int fd)
{
	int		i;
	char	*line;

	scene->ambient_light = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	i = 0;
	line = ft_strtrim(get_next_line(fd), " \t\r\b");
	while (line)
	{
		if (line[0] == 'A')
			scene->ambient_light = ft_is_double(scene,
					scene->ambient_light, line, fd);
		else if (line[0] == 'C')
			scene->camera = ft_is_double(scene, scene->camera, line, fd);
		else if (line[0] == 'L')
			scene->light = ft_is_double(scene, scene->light, line, fd);
		else if (line[0] != '\n' && line[0] != '#')
			scene->objects[i++] = ft_strdup(line);
		free(line);
		line = ft_strtrim(get_next_line(fd), " \t\r\b");
	}
}

t_scene	*ft_allocate_scene(char *file)
{
	t_scene	*scene;
	int		obj_count;
	int		fd;

	obj_count = ft_obj_count(file);
	scene = ft_calloc(sizeof(t_scene), 1);
	if (obj_count > 0)
	{
		scene->objects = ft_calloc(sizeof(char *), (obj_count + 1));
		if (!scene->objects)
			ft_exit(ERROR_MALLOC, 2);
		scene->objects[obj_count] = NULL;
	}
	fd = ft_get_fd(file);
	ft_put_argument(scene, fd);
	close(fd);
	return (scene);
}
