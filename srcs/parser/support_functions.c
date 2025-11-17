/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:46:12 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/17 16:20:44 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

///@brief this function verified if argument is .rt
int	ft_is_rt(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 3], ".rt", 3))
		return (1);
	return (0);
}

int	ft_get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(ERROR_FILE, 2);
	return (fd);
}

void	ft_free_split(char **arr)
{
	int	i;

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

void	ft_free_scene(t_args *args)
{
	if (args->ambient_light)
		free(args->ambient_light);
	if (args->camera)
		free(args->camera);
	if (args->light)
		free(args->light);
	if (args->objects)
		ft_free_split(args->objects);
	free(args);
}
