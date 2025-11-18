/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/18 15:38:38 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	debug_scene(t_args *args)
{
	int	i;

	i = 0;
	printf("\n===== SCENE =====\n");
	printf("Ambient light: %s\n", args->ambient_light);
	printf("Camera:        %s\n", args->camera);
	printf("Light:         %s\n", args->light);
	printf("Objects:\n");
	if (!args->objects)
		printf("  (objects == null)\n");
	else
	{
		i = 0;
		while (args->objects[i])
		{
			printf("  [%d] %s\n", i, args->objects[i]);
			i++;
		}
	}
	printf("\n=======================\n\n");
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc != 2 || ft_is_rt(argv[1]))
		ft_exit(ERROR_PARAM, 1);
	args = ft_get_args(argv[1]);
	debug_scene(args);
	ft_free_args(args);
	return (0);
}

void	ft_exit(char *message, int code)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(code);
}
