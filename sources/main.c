/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:30 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/10 11:54:16 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	key_hook(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->context);
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}

int main(int ac, char **av)
{
	t_mlx					mlx;
	mlx_window_create_info	info;

	(void)ac;
	(void)av;
	ft_bzero(&mlx, sizeof(mlx));
	ft_bzero(&info, sizeof(info));
	info.height = 963;
	info.width = 1920;
	info.title = "cub3D";
	mlx.context = mlx_init();
	mlx.window = mlx_new_window(mlx.context, &info);
	mlx_on_event(mlx.context, mlx.window, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.context, mlx.window, MLX_WINDOW_EVENT, window_hook, mlx.context);
	mlx_loop(mlx.context);
	mlx_destroy_window(mlx.context, mlx.window);
	mlx_destroy_context(mlx.context);
	return (0);
}
