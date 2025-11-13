/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-get_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:41 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/13 17:03:17 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**ft_get_scene(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit(ERROR_FILE, 2);
	close(fd);
	return (NULL);
}
