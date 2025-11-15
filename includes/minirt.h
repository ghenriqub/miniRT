/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/15 15:52:23 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"

# define ERROR_PARAM "Error\nUsage: ./minirt <file.rt>"
# define ERROR_FILE "Error\nCannot open this found."
# define ERROR_MALLOC "Error\nCannot allocate memmory."
# define ERROR_SCENE "Error\ninvalid scene."

typedef struct s_scene
{
	char	*ambient_light;
	char	*camera;
	char	*light;
	char	**objects;
}	t_scene;

//--- Parser
void	ft_exit(char *message, int code);
int		ft_is_rt(char *file);
t_scene	*ft_get_scene(char *file);
int		ft_get_fd(char *file);
void	ft_put_argument(t_scene *scene, int fd);
void	ft_free_scene(t_scene *scene);
t_scene	*ft_allocate_scene(char *file);

#endif