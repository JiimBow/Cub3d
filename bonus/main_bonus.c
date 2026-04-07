/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:09:40 by jodone            #+#    #+#             */
/*   Updated: 2026/04/07 17:28:43 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static int	parse_main(char **av, t_mlx *mlx, t_map *map, t_text *text)
{
	t_door	*door;

	door = NULL;
	if (map_is_not_valid(av[1], map))
		return (1);
	if (init_mlx_struct(mlx, map, text, &door))
	{
		destroy_image_window_context(mlx, map);
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
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_down, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYUP, key_up, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_mouse_move(mlx.cont, mlx.win, SCREEN_W / 2, SCREEN_H / 2);
	mlx_mouse_hide(mlx.cont);
	mlx_add_loop_hook(mlx.cont, update_frame, &mlx);
	mlx_add_loop_hook(mlx.cont, hitting, &mlx);
	mlx_loop(mlx.cont);
	destroy_image_window_context(&mlx, &map);
	return (mlx.signal);
}
