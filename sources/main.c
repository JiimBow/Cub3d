/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/18 13:08:24 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		wid;
	int		hei;

	if (ac != 2)
		return (error_message(0));
	if (!map_is_valid(av[1]))
		return (error_message(1));
	init_mlx_struct(&mlx);
	set_background(&mlx);
	mlx.wall = mlx_new_image_from_file(mlx.cont, "pics/eagle.png", &wid, &hei);
	mlx_put_image_to_window(mlx.cont, mlx.win, mlx.wall, 0, 0);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_down, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYUP, key_up, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update_frame, &mlx);
	mlx_loop(mlx.cont);
	mlx_destroy_image(mlx.cont, mlx.background);
	mlx_destroy_image(mlx.cont, mlx.wall);
	mlx_destroy_window(mlx.cont, mlx.win);
	mlx_destroy_context(mlx.cont);
	return (0);
}
