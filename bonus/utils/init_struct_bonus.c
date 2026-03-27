/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:15:34 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/27 17:27:31 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_ray_data(t_mlx *mlx, t_wall *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->ray_dir_x = mlx->dir_x + mlx->plane_x * ray->camera_x;
	ray->ray_dir_y = mlx->dir_y + mlx->plane_y * ray->camera_x;
	ray->map_x = (int)mlx->pos_x;
	ray->map_y = (int)mlx->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->step_x = (ray->ray_dir_x < 0) * -1 + (ray->ray_dir_x >= 0);
	ray->step_y = (ray->ray_dir_y < 0) * -1 + (ray->ray_dir_y >= 0);
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (mlx->pos_x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - mlx->pos_x) * ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (mlx->pos_y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - mlx->pos_y) * ray->delta_dist_y;
}

static int	put_color_value(mlx_color *color, char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_double_ptr(rgb);
		return (0);
	}
	if (!color_valid(rgb[0]) || !color_valid(rgb[1]) || !color_valid(rgb[2]))
	{
		free_double_ptr(rgb);
		return (0);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	color->a = 255;
	free_double_ptr(rgb);
	return (1);
}

void	set_all_textures(t_mlx *mlx, mlx_color *buf, mlx_image *img)
{
	int	x;
	int	y;
	int	i;

	x = TEX_WIDTH;
	i = 0;
	while (x-- > 0)
	{
		y = 0;
		while (y < TEX_HEIGHT)
			buf[i++] = mlx_get_image_pixel(mlx->cont, *img, x, y++);
	}
}

int	init_textures(t_mlx *mlx, t_text *text, t_map *map)
{
	if (load_image(mlx, text, map))
		return (1);
	set_all_textures(mlx, mlx->buf_no, &text->no_text);
	set_all_textures(mlx, mlx->buf_so, &text->so_text);
	set_all_textures(mlx, mlx->buf_we, &text->we_text);
	set_all_textures(mlx, mlx->buf_ea, &text->ea_text);
	set_all_textures(mlx, mlx->buf_do, &text->do_text);
	if (!put_color_value(&text->f_color, map->f_value))
		return (error_message(5));
	if (!put_color_value(&text->c_color, map->c_value))
		return (error_message(5));
	mlx->win = mlx_new_window(mlx->cont, &mlx->info);
	set_background(mlx, text);
	return (0);
}

int	init_mlx_struct(t_mlx *mlx, t_map *map, t_text *text, t_door *door)
{
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(&mlx->info, sizeof(mlx_window_create_info));
	ft_bzero(mlx->keys, 512);
	ft_bzero(text, sizeof(t_text));
	if (set_player_start(mlx, map))
		return (error_message(7));
	init_door_pos(mlx, map, door, 0);
	door = malloc(mlx->door_count * sizeof(t_door));
	init_door_pos(mlx, map, door, 1);
	mlx->cont = mlx_init();
	if (!mlx->cont)
		return (error_message(9));
	gettimeofday(&mlx->last_time, NULL);
	mlx_set_fps_goal(mlx->cont, 90);
	mlx->s_text = text;
	mlx->s_map = map;
	mlx->s_door = door;
	mlx->info.height = SCREEN_H;
	mlx->info.width = SCREEN_W;
	mlx->info.title = "cub3D";
	mlx->fps_timer = 1.0;
	mlx->sp_move = 2.0;
	mlx->sp_rot = 3.0;
	mlx->zoom = 4;
	set_minimap(mlx);
	return (0);
}
