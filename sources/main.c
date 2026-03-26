/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/26 09:58:01 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_image_window_context(t_mlx *mlx, t_map *map)
{
	if (mlx->buf_no)
		free(mlx->buf_no);
	if (mlx->buf_so)
		free(mlx->buf_so);
	if (mlx->buf_ea)
		free(mlx->buf_ea);
	if (mlx->buf_we)
		free(mlx->buf_we);
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
	if (mlx->minimap)
		mlx_destroy_image(mlx->cont, mlx->minimap);
	if (mlx->win)
		mlx_destroy_window(mlx->cont, mlx->win);
	if (mlx->cont)
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
	if (init_mlx_struct(&mlx, &map, &text))
	{
		free_map(&map);
		return (1);
	}
	if (init_textures(&mlx, &text, &map))
	{
		destroy_image_window_context(&mlx, &map);
		return (1);
	}
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
