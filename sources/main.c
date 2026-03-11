/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 16:56:08 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx					mlx;
	mlx_image				background;

	if (ac != 2)
		return (error_message(0));
	if (!map_is_valid(av[1]))
		return (error_message(1));
	init_mlx_struct(&mlx);
	background = set_background(mlx);
	mlx_put_image_to_window(mlx.context, mlx.window, background, 0, 0);
	mlx_on_event(mlx.context, mlx.window, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.context, mlx.window, MLX_WINDOW_EVENT, window_hook, mlx.context);
	mlx_add_loop_hook(mlx.context, update_frame, &mlx);
	mlx_loop(mlx.context);
	mlx_destroy_image(mlx.context, background);
	mlx_destroy_window(mlx.context, mlx.window);
	mlx_destroy_context(mlx.context);
	return (0);
}
