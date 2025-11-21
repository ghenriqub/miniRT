/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:44:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/21 21:48:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
static void ft_print_vec3(t_vec3 v)
{
    printf("(%.3f, %.3f, %.3f)", v.x, v.y, v.z);
}

static void ft_print_rgb(t_rgb c)
{
    printf("(%d, %d, %d)", c.r, c.g, c.b);
}

static const char *ft_obj_name(t_obj_type t)
{
    if (t == SPHERE) return "SPHERE";
    if (t == PLANE) return "PLANE";
    if (t == CYLINDER) return "CYLINDER";
    return "UNKNOWN";
}

static void ft_print_object_data(t_object *obj)
{
    if (!obj || !obj->data)
        return;

    if (obj->type == SPHERE)
    {
        t_sphere *s = (t_sphere *)obj->data;
        printf("      center = ");
        ft_print_vec3(s->center);
        printf("\n      diameter = %.3f\n", s->diameter);
    }
    else if (obj->type == PLANE)
    {
        t_plane *p = (t_plane *)obj->data;
        printf("      point  = ");
        ft_print_vec3(p->point);
        printf("\n      normal = ");
        ft_print_vec3(p->normal);
        printf("\n");
    }
    else if (obj->type == CYLINDER)
    {
        t_cylinder *c = (t_cylinder *)obj->data;
        printf("      center = ");
        ft_print_vec3(c->center);
        printf("\n      normal = ");
        ft_print_vec3(c->normal);
        printf("\n      diameter = %.3f\n", c->diameter);
        printf("      height = %.3f\n", c->height);
    }
}

void ft_print_scene(t_scene *scene)
{
    if (!scene)
        return;

    printf("\n=========== SCENE ===========\n");

    // AMBIENT LIGHT 
    if (scene->ambient)
    {
        printf("\nAmbient Light:\n");
        printf("  ratio = %.3f\n", scene->ambient->ratio);
        printf("  color = ");
        ft_print_rgb(scene->ambient->color);
        printf("\n");
    }

    // CAMERA 
    if (scene->camera)
    {
        printf("\nCamera:\n");
        printf("  position = ");
        ft_print_vec3(scene->camera->position);
        printf("\n  vector   = ");
        ft_print_vec3(scene->camera->vector);
        printf("\n  fov      = %d\n", scene->camera->fov);
    }

    // LIGHTS 
    printf("\nLights (%d):\n", scene->light_count);
    for (int i = 0; i < scene->light_count; i++)
    {
        printf("  Light %d:\n", i);
        printf("    position = ");
        ft_print_vec3(scene->lights[i]->position);
        printf("\n    ratio = %.3f\n", scene->lights[i]->ratio);
        printf("    color = ");
        ft_print_rgb(scene->lights[i]->color);
        printf("\n");
    }

    // OBJECTS 
    printf("\nObjects (%d):\n", scene->object_count);
    for (int i = 0; i < scene->object_count; i++)
    {
        printf("  Object %d:\n", i);
        printf("    type = %s\n", ft_obj_name(scene->objects[i]->type));
        ft_print_object_data(scene->objects[i]);
    }

    printf("\n==============================\n\n");
}*/

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2 || ft_is_rt(argv[1]))
		ft_exit(ERROR_PARAM, 1);
	scene = ft_get_scene(argv[1]);
	//ft_print_scene(scene);
	ft_free_scene(scene);
	return (0);
}

void	ft_exit(char *message, int code)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(code);
}
