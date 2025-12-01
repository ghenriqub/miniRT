/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/12/01 19:42:58 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <stdbool.h>
# include <math.h>

# define ERROR_PARAM "Error\nUsage: ./minirt <file.rt>"
# define ERROR_FILE "Error\nCannot open this found."
# define ERROR_MALLOC "Error\nCannot allocate memmory."
# define ERROR_SCENE "Error\ninvalid scene."
# define WIDTH 800
# define HEIGHT 1400

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
	t_vec3	normal;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	normal;
	float	diameter;
	float	height;
	t_rgb	color;
}	t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	INVALID
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	void		*data;
}	t_object;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_graphics;

typedef struct s_scene
{
	t_ambient_light	*ambient;
	t_camera		*camera;
	t_light			**lights;
	int				light_count;
	t_object		**objects;
	int				object_count;
	t_graphics		disp;

}	t_scene;

// typedef struct s_world
// {
// 	t_camera	camera;
// 	t_light		ambient;
// 	t_vec3		*lights;
// 	t_vec3		*shapes;
// 	int			counters[3];
// 	t_graphics	disp;
// 	t_vec3		up;
// 	t_vec3		right;
// 	char		**map;
// 	double		hview;
// 	double		wview;
// }	t_world;

// ============ Parser ============

void			ft_exit(char *message, int code);
int				ft_is_rt(char *file);
t_scene			*ft_get_scene(char *file);
int				ft_get_fd(char *file);
void			ft_put_argument(t_args *args, int fd);
void			ft_free_args(t_args *args);
t_scene			*ft_parser(t_args *args);
t_args			*ft_allocate_args(char *file);
t_ambient_light	*ft_parser_al(char *input);
t_camera		*ft_parser_c(char *input);
t_light			**ft_parser_l(char **input, int count_light);
t_object		**ft_parser_ob(char **input, int count_objects);
t_rgb			ft_get_rgb(char *str);
float			ft_atof(const char *str);
int				ft_parser_rgb(char *str);
t_camera		*ft_parser_c(char *input);
int				ft_parser_ratio(char *str, float min, float max);
int				ft_is_normalized(char *str);
int				ft_is_number(char *str);
int				ft_parser_vec3(char *str);
t_vec3			ft_get_vec3(char *str);
int				ft_float_format(const char *str);
int				ft_parse_fov(char *str);
void			**ft_alloc_arraystruc(int count, size_t type_size);
void			ft_free_arraystruc(void **arr, int count);
void			ft_free_scene(t_scene *scene);
void			ft_free_split(char **arr);
void			*ft_get_obj(t_obj_type type, char *line);
t_obj_type		ft_get_type(char *line);
char			*ft_tab_to_space(char *str);
void			ft_free_objects_struc(t_object **arr, int count);

// ============ Vectors ============
t_vec3			vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3			atovec3(char **vec);
bool			vec3_cmp(t_vec3 vec1, t_vec3 vec2);
double			vec3_cos(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_cross(t_vec3 vec1, t_vec3 vec2);
double			vec3_dot(t_vec3 vec1, t_vec3 vec2);
double			vec3_len(t_vec3 vec);
t_vec3			vec3_new(double x, double y, double z);
t_vec3  		vec3_normalize(t_vec3 vec);
t_vec3			vec3_scale(t_vec3 vec1, double scalar);
t_vec3  		vec3_sub(t_vec3 vec1, t_vec3 vec2);

#endif
