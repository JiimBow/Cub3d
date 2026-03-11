/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:02:47 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 15:09:25 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_delta_time(t_mlx *mlx)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	mlx->delta = (now.tv_sec - mlx->last_time.tv_sec)
		+ (now.tv_usec - mlx->last_time.tv_usec) / 1000000.0f;
	mlx->last_time = now;
}

void	update_frame(void *param)
{
	t_mlx		*mlx;
	char		title[64];
	const char	*base = "Cub3D - FPS: ";
	char		*buff;

	mlx = param;
	get_delta_time(mlx);

	mlx->fps_timer += mlx->delta;
	mlx->frame_count++;

	if (mlx->fps_timer >= 1.0)
	{
		mlx->fps = mlx->frame_count;
		mlx->frame_count = 0;
		mlx->fps_timer = 0.0;
		ft_strlcpy(title, base, ft_strlen(base) + 1);
		buff = ft_itoa(mlx->fps);
		ft_strlcpy(title + ft_strlen(title), buff, ft_strlen(buff) + 1);
		free(buff);
		mlx_set_window_title(mlx->context, mlx->window, title);
	}
}
