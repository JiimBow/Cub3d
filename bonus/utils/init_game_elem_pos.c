/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_elem_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:14:45 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 16:08:04 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_game_count(t_map *map, char type)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map->map && map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == type)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_door_pos(t_map *map, t_door *door)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'D')
			{
				door[i].pos_x = x;
				door[i].pos_y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_sprite_pos(t_map *map, t_sprite *sprite)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '2')
			{
				sprite[i].pos_x = x;
				sprite[i].pos_y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
