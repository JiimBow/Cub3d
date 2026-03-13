/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/13 11:13:16 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx		mlx;

	(void)av;
	if (ac != 2)
		return (error_message(0));
	init_mlx_struct(&mlx);
	mlx.background = set_background(mlx);
	mlx.wall = mlx_new_image(mlx.cont, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_put_image_to_window(mlx.cont, mlx.win, mlx.background, 0, 0);
	mlx_put_image_to_window(mlx.cont, mlx.win, mlx.wall, 0, 0);
	mlx_on_event(mlx.cont, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.cont, mlx.win, MLX_WINDOW_EVENT, window_hook, mlx.cont);
	mlx_add_loop_hook(mlx.cont, update_frame, &mlx);
	mlx_loop(mlx.cont);
	mlx_destroy_image(mlx.cont, mlx.background);
	mlx_destroy_image(mlx.cont, mlx.wall);
	mlx_destroy_window(mlx.cont, mlx.win);
	mlx_destroy_context(mlx.cont);
	return (0);
}
