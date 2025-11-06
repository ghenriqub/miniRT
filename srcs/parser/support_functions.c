/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:46:12 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/06 17:46:55 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_exit(char *message, int code)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(code);
}

int	ft_is_rt(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 3], ".rt", 3))
		return (1);
	return (0);
}
