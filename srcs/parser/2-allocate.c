/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-allocate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:08:27 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/21 20:49:06 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_is_object(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(&line[i], "sp ", 3))
		return (1);
	if (!ft_strncmp(&line[i], "pl ", 3))
		return (1);
	if (!ft_strncmp(&line[i], "cy ", 3))
		return (1);
	return (0);
}

static int	*ft_count(char *file)
{
	int		*count;
	int		fd;
	char	*line;
	int		i;

	count = ft_calloc(2, sizeof(int));
	if (!count)
		ft_exit(ERROR_MALLOC, 2);
	fd = ft_get_fd(file);
	line = ft_strtrim(get_next_line(fd), " \t\r\b\n");
	while (line)
	{
		i = 0;
		ft_tab_to_space(line);
		while (line[i] == ' ')
			i++;
		if (!ft_strncmp(&line[i], "L ", 2))
			count[0]++;
		else if (ft_is_object(line))
			count[1]++;
		free(line);
		line = ft_strtrim(get_next_line(fd), " \t\r\b\n");
	}
	close(fd);
	return (count);
}

static char	*ft_is_double(t_args *args, char *target, char *line, int fd)
{
	if (target)
	{
		free(line);
		ft_free_args(args);
		close(fd);
		ft_exit(ERROR_SCENE, 2);
	}
	return (ft_strdup(line));
}

// 1 - set args NULL
// 2 - strtrim for erase spaces
// 3 - fill scruct according the type of the lines
// 4 - Cam and ambient light can't duplicate
// if invalid argument, call ft_is_double for free and exit
void	ft_put_argument(t_args *args, int fd)
{
	int		i;
	int		k;
	char	*line;

	args->ambient_light = NULL;
	i = 0;
	k = 0;
	line = ft_strtrim(get_next_line(fd), " \t\r\b\n");
	while (line)
	{
		ft_tab_to_space(line);
		if (!ft_strncmp(line, "A ", 2))
			args->ambient_light = ft_is_double(args,
					args->ambient_light, line, fd);
		else if (!ft_strncmp(line, "C ", 2))
			args->camera = ft_is_double(args, args->camera, line, fd);
		else if (!ft_strncmp(line, "L ", 2))
			args->light[k++] = ft_strdup(line);
		else if (ft_is_object(line))
			args->objects[i++] = ft_strdup(line);
		else if (line[0] != '\n' && line[0] != '#')
			ft_is_double(args, "invalid", line, fd);
		free(line);
		line = ft_strtrim(get_next_line(fd), " \t\r\b\n");
	}
}

// 1- call ft_count to get number of the Lights and objets
// 2 - allocate memory for struct and arrays-arrays
// 3 - call ft_put_argument to fill struct
t_args	*ft_allocate_args(char *file)
{
	t_args	*args;
	int		*count;
	int		fd;

	count = ft_count(file);
	args = ft_calloc(sizeof(t_args), 1);
	args->camera = NULL;
	args->light_count = count[0];
	args->obj_count = count[1];
	free(count);
	args->objects = ft_calloc(sizeof(char *), (args->obj_count + 1));
	if (!args->objects)
		ft_exit(ERROR_MALLOC, 2);
	args->objects[args->obj_count] = NULL;
	if (args->light_count > 0)
	{
		args->light = ft_calloc(sizeof(char *), (args->light_count + 1));
		if (!args->light_count)
			ft_exit(ERROR_MALLOC, 2);
		args->objects[args->light_count] = NULL;
	}
	fd = ft_get_fd(file);
	ft_put_argument(args, fd);
	close(fd);
	return (args);
}
