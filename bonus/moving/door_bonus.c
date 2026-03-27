/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:05:21 by jodone            #+#    #+#             */
/*   Updated: 2026/03/27 11:05:36 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	close_door(t_mlx *mlx, double player_x, double player_y)
{
	if (mlx->s_map->map[(int)player_y + 1][(int)player_x + 1] == 'O')
		mlx->s_map->map[(int)player_y + 1][(int)player_x + 1] = 'D';
	if (mlx->s_map->map[(int)player_y - 1][(int)player_x - 1] == 'O')
		mlx->s_map->map[(int)player_y - 1][(int)player_x - 1] = 'D';
	if (mlx->s_map->map[(int)player_y + 1][(int)player_x - 1] == 'O')
		mlx->s_map->map[(int)player_y + 1][(int)player_x - 1] = 'D';
	if (mlx->s_map->map[(int)player_y - 1][(int)player_x + 1] == 'O')
		mlx->s_map->map[(int)player_y - 1][(int)player_x + 1] = 'D';
	if (mlx->s_map->map[(int)player_y + 2][(int)player_x] == 'O')
		mlx->s_map->map[(int)player_y + 2][(int)player_x] = 'D';
	if (mlx->s_map->map[(int)player_y - 2][(int)player_x] == 'O')
		mlx->s_map->map[(int)player_y - 2][(int)player_x] = 'D';
	if (mlx->s_map->map[(int)player_y][(int)player_x + 2] == 'O')
		mlx->s_map->map[(int)player_y][(int)player_x + 2] = 'D';
	if (mlx->s_map->map[(int)player_y][(int)player_x - 2] == 'O')
		mlx->s_map->map[(int)player_y][(int)player_x - 2] = 'D';
}

void	open_door(t_mlx *mlx, double player_x, double player_y)
{
	if (mlx->s_map->map[(int)player_y + 1][(int)player_x] == 'D')
		mlx->s_map->map[(int)player_y + 1][(int)player_x] = 'O';
	if (mlx->s_map->map[(int)player_y - 1][(int)player_x] == 'D')
		mlx->s_map->map[(int)player_y - 1][(int)player_x] = 'O';
	if (mlx->s_map->map[(int)player_y][(int)player_x + 1] == 'D')
		mlx->s_map->map[(int)player_y][(int)player_x + 1] = 'O';
	if (mlx->s_map->map[(int)player_y][(int)player_x - 1] == 'D')
		mlx->s_map->map[(int)player_y][(int)player_x - 1] = 'O';
}
