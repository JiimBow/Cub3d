/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:09:29 by jodone            #+#    #+#             */
/*   Updated: 2026/03/11 16:12:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_game_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	first_row_is_valid(char **map, int *map_line, int map_col)
{
	int is_first;

	is_first = 0;
	while (map && map[(*map_line)])
	{
		while (map[(*map_line)][map_col])
		{
			if (is_space(map[(*map_line)][map_col])
				|| map[(*map_line)][map_col] == '1'
				|| map[(*map_line)][map_col] == '\n')
			{
				if (map[(*map_line)][map_col] == '1' && is_first == 0)
					is_first = 1;
				map_col++;
				continue ;
			}
			else
				return (0);
		}
		if (is_first == 1)
			return (1);
		(*map_line)++;
	}
	return (1);
}

static int	check_row(char **map, int map_line, int map_col)
{
	int	f_wall;

	f_wall = 0;
	while (map[map_line][map_col])
	{
		if (is_space(map[map_line][map_col]))
			map_col++;
		else if (map[map_line][map_col] == '1' && f_wall == 0)
			f_wall = 1;
		else if ((is_game_char(map[map_line][map_col])
			|| map[map_line][map_col] == '\n') && f_wall == 1)
			map_col++;
		else
			return (0);
	}
	return (1);
}

int	check_map(char **map)
{
	int	map_line;
	int	map_col;

	map_line = 0;
	if (!first_row_is_valid(map, &map_line, 0))
		return (0);
	while (map && map[map_line])
	{
		if (!check_row(map, map_line, 0))
			return (0);
		map_line++;
	}
	return (1);
}
