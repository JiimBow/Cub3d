/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:09:40 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 16:16:40 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	destroy_image_window_context(t_mlx *mlx, t_map *map)
{
	free_color(mlx);
	if (mlx->buf_do)
		free(mlx->buf_do);
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
	if (mlx->s_text->do_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->do_text);
	if (mlx->wall)
		mlx_destroy_image(mlx->cont, mlx->wall);
	if (mlx->minimap)
		mlx_destroy_image(mlx->cont, mlx->minimap);
	if (mlx->samourai[0])
		mlx_destroy_image(mlx->cont, mlx->samourai[0]);
	if (mlx->samourai[1])
		mlx_destroy_image(mlx->cont, mlx->samourai[1]);
	if (mlx->win)
		mlx_destroy_window(mlx->cont, mlx->win);
	if (mlx->cont)
		mlx_destroy_context(mlx->cont);
	if (mlx->spr)
		free(mlx->spr);
	if (mlx->s_door)
		free(mlx->s_door);
	free_map(map);
}

static int	parse_main(char **av, t_mlx *mlx, t_map *map, t_text *text)
{
	t_door	*door;

	door = NULL;
	if (map_is_not_valid(av[1], map))
		return (1);
	if (init_mlx_struct(mlx, map, text, door))
	{
		free_map(map);
		return (1);
	}
	if (init_textures(mlx, text, map))
	{
		destroy_image_window_context(mlx, map);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;
	t_text	text;

	if (ac != 2)
		return (error_message(0));
	if (parse_main(av, &mlx, &map, &text))
		return (1);
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
