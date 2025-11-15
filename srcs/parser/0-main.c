/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/15 15:55:30 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	debug_scene(t_scene *scene)
{
	int	i;

	i = 0;
	printf("\n===== SCENE =====\n");
	printf("Ambient light: %s\n", scene->ambient_light);
	printf("Camera:        %s\n", scene->camera);
	printf("Light:         %s\n", scene->light);
	printf("Objects:\n");
	if (!scene->objects)
		printf("  (objects == null)\n");
	else
	{
		i = 0;
		while (scene->objects[i])
		{
			printf("  [%d] %s\n", i, scene->objects[i]);
			i++;
		}
	}
	printf("\n=======================\n\n");
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2 || ft_is_rt(argv[1]))
		ft_exit(ERROR_PARAM, 1);
	scene = ft_get_scene(argv[1]);
	debug_scene(scene);
	ft_free_scene(scene);
	return (0);
}

void	ft_exit(char *message, int code)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(code);
}
