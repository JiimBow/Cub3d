/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:07:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/18 19:51:32 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_background(t_mlx *mlx, t_text *text)
{
	int	x;
	int	y;

	mlx->background = mlx_new_image(mlx->cont, SCREEN_WIDTH, SCREEN_HEIGHT);
	y = 0;
	while (y < mlx->info.height)
	{
		x = 0;
		while (y < mlx->info.height / 2 && x < mlx->info.width)
		{
			mlx_set_image_pixel(mlx->cont, mlx->background, x, y,
				text->c_color);
			x++;
		}
		x = 0;
		while (y >= mlx->info.height / 2
			&& y < mlx->info.height && x < mlx->info.width)
		{
			mlx_set_image_pixel(mlx->cont, mlx->background, x, y,
				text->f_color);
			x++;
		}
		y++;
	}
}
