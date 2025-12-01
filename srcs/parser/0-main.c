/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/01 16:39:18 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2 || ft_is_rt(argv[1]))
		ft_exit(ERROR_PARAM, 1);
	scene = ft_get_scene(argv[1]);
	ft_free_scene(scene);
	return (0);
}

void	ft_exit(char *message, int code)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(code);
}
