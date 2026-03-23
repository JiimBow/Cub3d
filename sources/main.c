/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/23 17:02:24 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_image_window_context(t_mlx *mlx, t_map *map)
{
	if (mlx->background)
		mlx_destroy_image(mlx->cont, mlx->background);
	if (mlx->s_text->no_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->no_text);
	if (mlx->s_text->so_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->so_text);
	if (mlx->s_text->we_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->we_text);
	if (mlx->s_text->ea_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->ea_text);
	if (mlx->wall)
		mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->minimap);
	mlx_destroy_window(mlx->cont, mlx->win);
	mlx_destroy_context(mlx->cont);
	free_map(map);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;
	t_text	text;

	if (ac != 2)
		return (error_message(0));
	if (map_is_not_valid(av[1], &map))
		return (1);
	init_mlx_struct(&mlx, &map, &text);
	if (init_textures(&mlx, &text, &map) == 1)
	{
		destroy_image_window_context(&mlx, &map);
		return (1);
	}
	set_background(&mlx, &text);
	mlx.wall = mlx_new_image(mlx.cont, SCREEN_W, SCREEN_H);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_down, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYUP, key_up, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_mouse_move(mlx.cont, mlx.win, SCREEN_W / 2, SCREEN_H / 2);
	mlx_mouse_hide(mlx.cont);
	mlx_add_loop_hook(mlx.cont, update_frame, &mlx);
	mlx_loop(mlx.cont);
	destroy_image_window_context(&mlx, &map);
	return (0);
}
