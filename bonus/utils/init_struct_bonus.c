/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:15:34 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/07 17:15:21 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	set_all_textures(t_mlx *mlx, mlx_color *buf, mlx_image img)
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
			buf[i++] = mlx_get_image_pixel(mlx->cont, img, x, y++);
	}
}

int	init_textures(t_mlx *mlx, t_text *text, t_map *map)
{
	mlx->wall = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
	if (!mlx->wall)
		return (1);
	if (load_image(mlx, text, map))
		return (1);
	set_all_textures(mlx, mlx->buf_no, text->no_text);
	set_all_textures(mlx, mlx->buf_so, text->so_text);
	set_all_textures(mlx, mlx->buf_we, text->we_text);
	set_all_textures(mlx, mlx->buf_ea, text->ea_text);
	set_all_textures(mlx, mlx->buf_do, text->do_text);
	if (!text->no_text || !text->so_text || !text->we_text
		|| !text->ea_text || !text->do_text)
		printf("error\n");
	if (!put_color_value(&text->f_color, map->f_value))
		return (error_message(5));
	if (!put_color_value(&text->c_color, map->c_value))
		return (error_message(5));
	mlx->win = mlx_new_window(mlx->cont, &mlx->info);
	set_background(mlx, text);
	if (mlx->sprite_count != 0)
		if (set_sprite_start(mlx, 0, 0))
			return (error_message(2));
	return (0);
}

int	allocation(t_mlx *mlx, t_map *map, t_door **door)
{
	t_sprite	*sprite;

	mlx->door_count = init_game_count(map, 'D');
	*door = malloc(mlx->door_count * sizeof(t_door));
	if (!*door)
		return (error_message(8));
	mlx->clear = malloc((SCREEN_H * SCREEN_W) * sizeof(mlx_color));
	if (!mlx->clear)
	{
		free(*door);
		return (error_message(8));
	}
	mlx->sprite_count = init_game_count(map, '2');
	if (mlx->sprite_count != 0)
	{
		sprite = malloc((mlx->sprite_count) * sizeof(t_sprite));
		if (!sprite)
		{
			free(*door);
			return (error_message(8));
		}
		mlx->spr = sprite;
	}
	return (0);
}

int	init_mlx_struct(t_mlx *mlx, t_map *map, t_text *text, t_door **door)
{
	ft_bzero(mlx, sizeof(t_mlx));
	ft_bzero(&mlx->info, sizeof(mlx_window_create_info));
	ft_bzero(mlx->keys, 512);
	ft_bzero(text, sizeof(t_text));
	mlx->s_text = text;
	mlx->s_map = map;
	if (allocation(mlx, map, door))
		return (1);
	mlx->s_door = *door;
	ft_bzero(mlx->clear, SCREEN_H * SCREEN_W * sizeof(mlx_color));
	init_door_pos(map, *door);
	init_sprite_pos(map, mlx->spr);
	gettimeofday(&mlx->last_time, NULL);
	if (set_player_start(mlx, map))
		return (error_message(7));
	mlx->cont = mlx_init();
	if (!mlx->cont)
		return (error_message(9));
	mlx_set_fps_goal(mlx->cont, 90);
	set_mlx_struct(mlx);
	set_minimap(mlx, map);
	return (0);
}
