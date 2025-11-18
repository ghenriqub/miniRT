/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/18 16:04:53 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"

# define ERROR_PARAM "Error\nUsage: ./minirt <file.rt>"
# define ERROR_FILE "Error\nCannot open this found."
# define ERROR_MALLOC "Error\nCannot allocate memmory."
# define ERROR_SCENE "Error\ninvalid scene."

typedef struct s_args
{
	char	*ambient_light;
	char	*camera;
	char	**light;
	int		light_count;
	char	**objects;
	int		obj_count;
}	t_args;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ambient_light
{
	float	ratio;
	t_rgb	color;
}	t_ambient_light;

typedef struct s_camera
{
	t_point	position;
	t_vec	vector;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_point	position;
	float	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_point	center;
	float	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_point	point;
	t_vec	vector;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_point	center;
	t_vec	vector;
	float	diameter;
	float	height;
	t_rgb	color;
}	t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	void		*data;
}	t_object;

typedef struct s_scene
{
	t_ambient_light	ambient;
	t_camera		camera;
	t_light			*lights;
	int				light_count;
	t_object		*objects;
	int				object_count;
}	t_scene;

//--- Parser
void	ft_exit(char *message, int code);
int		ft_is_rt(char *file);
t_args	*ft_get_args(char *file);
int		ft_get_fd(char *file);
void	ft_put_argument(t_args *args, int fd);
void	ft_free_args(t_args *args);
//void	ft_parser(t_scene *args);
t_args	*ft_allocate_args(char *file);

#endif
