/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:22:36 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/23 16:59:45 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_mlx *mlx, t_wall *ray)
{
	int	x;
	int	y;
	int	max = 0;
	
	(void)ray;
	y = 0;
	while (mlx->s_map->map[y][0] == '\0' || mlx->s_map->map[y][0] == '\n')
		mlx->s_map->map++;
	while (mlx->s_map->map[y])
	{
		printf("mlx->s_map->map[y]=%s\n", mlx->s_map->map[y]);
		x = 0;
		while (mlx->s_map->map[y][x])
		{
			x++;
		}
		if (x - 1 > max)
			max = x;
		y++;
	}
	y = 0;
	while (mlx->s_map->map[y])
	{
		x = 0;
		while (mlx->s_map->map[y][x])
		{
			if (mlx->s_map->map[y][x] > 1)
				mlx_set_image_pixel(mlx->cont, mlx->minimap, x, y, (mlx_color)RGB_RED);
			x++;
		}
		y++;
	}
	mlx_set_image_region(mlx->cont, mlx->minimap, 0, 0, x, y, mlx->buf_minimap);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->minimap, 10, 10, 4, 4, 0);
}
