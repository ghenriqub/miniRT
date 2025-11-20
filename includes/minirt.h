/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 16:32:53 by lgertrud         ###   ########.fr       */
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

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

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
	t_vec3	position;
	t_vec3	vector;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	position;
	float	ratio;
	t_rgb	color;
}	t_light;

typedef struct s_sphere
{
	t_vec3	center;
	float	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	vector;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	vector;
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
	t_ambient_light	*ambient;
	t_camera		*camera;
	t_light			**lights;
	int				light_count;
	t_object		**objects;
	int				object_count;
}	t_scene;

//--- Parser
void			ft_exit(char *message, int code);
int				ft_is_rt(char *file);
t_args			*ft_get_scene(char *file);
int				ft_get_fd(char *file);
void			ft_put_argument(t_args *args, int fd);
void			ft_free_args(t_args *args);
void			ft_parser(t_scene *args);
t_args			*ft_allocate_args(char *file);
t_ambient_light	*ft_parser_al(char *input);
t_rgb			ft_get_rgb(char *str);
float			ft_atof(const char *str);
int				ft_parser_rgb(char *str);
t_camera		*ft_parser_c(char *input);
int				ft_parser_ratio(char *str, float min, float max);
int				ft_is_normalized(char *str);
int				ft_parse_vec3(char *str);
t_vec3			ft_get_vec3(char *str);
int				ft_float_format(const char *str);
int				ft_parse_fov(char *str);
void			**ft_alloc_arraystruc(int count, size_t type_size);
void			ft_free_arraystruc(void **arr, int count);

#endif
