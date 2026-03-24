/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:22:36 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/24 13:32:24 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_minimap(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->old_pos_x = mlx->pos_x;
	mlx->old_pos_y = mlx->pos_y;
	mlx->minimap = mlx_new_image(mlx->cont, SCREEN_W / 10, SCREEN_H / 10);
	y = 0;
	while (mlx->s_map->map[y])
	{
		x = 0;
		while (mlx->s_map->map[y][x])
		{
			if (mlx->s_map->map[y][x] == '1')
				mlx_set_image_pixel(mlx->cont, mlx->minimap, x, y,
					(mlx_color){.rgba = 0x0000001a});
			x++;
		}
		y++;
	}
}

void	put_minimap_on_map(t_mlx *mlx)
{
	mlx_set_image_pixel(mlx->cont, mlx->minimap,
		mlx->old_pos_x, mlx->old_pos_y, (mlx_color){0});
	mlx_set_image_pixel(mlx->cont, mlx->minimap,
		mlx->pos_x, mlx->pos_y, (mlx_color)RGB_RED);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
		mlx->minimap, 10, 10, mlx->zoom, mlx->zoom, 0);
	mlx->old_pos_x = mlx->pos_x;
	mlx->old_pos_y = mlx->pos_y;
	return ;
}
