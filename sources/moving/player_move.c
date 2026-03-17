/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/16 17:25:25 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(t_mlx *mlx, int key, int delx, int dely)
{
	int	playerX;
	int	playerY;

	playerX = (int)mlx->pos_x;
	playerY = (int)mlx->pos_y;
	if (key == W)
		dely--;
	else if (key == A)
		delx--;
	else if (key == S)
		dely++;
	else if (key == D)
		delx++;
	if (g_world_map[playerY + dely][playerX + delx] == 0 && (delx != 0  || dely != 0))
	{
		mlx->pos_x += delx;
		mlx->pos_y += dely;
	}
	return (0);
}
