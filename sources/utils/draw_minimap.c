/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:22:36 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/23 17:30:07 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_mlx *mlx, t_wall *ray)
{
	int	x;
	int	y;
	
	(void)ray;
	y = 0;
	while (mlx->s_map->map[y])
	{
		x = 0;
		while (mlx->s_map->map[y][x])
		{
			if (mlx->s_map->map[y][x] == '1')
				mlx_set_image_pixel(mlx->cont, mlx->minimap, x, y, (mlx_color){.rgba = 0x0000001a});
			x++;
		}
		y++;
	}
	mlx_set_image_region(mlx->cont, mlx->minimap, 0, 0, x + 1, y + 1, mlx->buf_minimap);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->minimap, 10, 10, 4, 8, 0);
}
