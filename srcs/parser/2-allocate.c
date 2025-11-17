/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-allocate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:08:27 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/17 16:19:20 by lgertrud         ###   ########.fr       */
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

static char	*ft_is_double(t_args *args, char *target, char *line, int fd)
{
	if (target)
	{
		free(line);
		ft_free_scene(args);
		close(fd);
		ft_exit(ERROR_SCENE, 2);
	}
	return (ft_strdup(line));
}

void	ft_put_argument(t_args *args, int fd)
{
	int		i;
	char	*line;

	args->ambient_light = NULL;
	args->camera = NULL;
	args->light = NULL;
	i = 0;
	line = ft_strtrim(get_next_line(fd), " \t\r\b");
	while (line)
	{
		if (!ft_strncmp(line, "A ", 2))
			args->ambient_light = ft_is_double(args,
					args->ambient_light, line, fd);
		else if (!ft_strncmp(line, "C ", 2))
			args->camera = ft_is_double(args, args->camera, line, fd);
		else if (!ft_strncmp(line, "L ", 2))
			args->light = ft_is_double(args, args->light, line, fd);
		else if (line[0] != '\n' && line[0] != '#')
			args->objects[i++] = ft_strdup(line);
		free(line);
		line = ft_strtrim(get_next_line(fd), " \t\r\b");
	}
}

t_args	*ft_allocate_scene(char *file)
{
	t_args	*args;
	int		obj_count;
	int		fd;

	obj_count = ft_obj_count(file);
	args = ft_calloc(sizeof(t_args), 1);
	if (obj_count > 0)
	{
		args->objects = ft_calloc(sizeof(char *), (obj_count + 1));
		if (!args->objects)
			ft_exit(ERROR_MALLOC, 2);
		args->objects[obj_count] = NULL;
	}
	fd = ft_get_fd(file);
	ft_put_argument(args, fd);
	close(fd);
	return (args);
}
