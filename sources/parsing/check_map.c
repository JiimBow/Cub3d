/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:09:29 by jodone            #+#    #+#             */
/*   Updated: 2026/04/08 11:30:50 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_game_char(char c)
{
	static int	start_nb = 0;

	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && start_nb == 0)
	{
		start_nb++;
		return (1);
	}
	return (0);
}

static int	zero_check(char **map, int map_line, int map_col)
{
	if (map[map_line - 1][0])
	{
		if (map[map_line - 1][map_col - 1] == ' '
			|| map[map_line - 1][map_col] == ' '
			|| map[map_line - 1][map_col + 1] == ' '
			|| !map[map_line - 1][map_col + 1]
			|| map[map_line - 1][map_col + 1] == '\n')
			return (0);
	}
	if (map[map_line][map_col - 1] == ' ' || map[map_line][map_col + 1] == ' ')
		return (0);
	if (map[map_line + 1])
	{
		if (map[map_line + 1][map_col - 1] == ' '
			|| map[map_line + 1][map_col] == ' '
			|| map[map_line + 1][map_col + 1] == ' '
			|| !map[map_line + 1][map_col + 1])
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	first_row_is_valid(char **map, int *map_line, int map_col)
{
	int	is_first;

	is_first = 0;
	while (map && map[(*map_line)])
	{
		map_col = 0;
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
	return (0);
}

static int	check_row(char **map, int line, int col)
{
	int	f_wall;

	f_wall = 0;
	while (map[line][col])
	{
		if (is_space(map[line][col]))
			col++;
		else if (map[line][col] == '1' && f_wall == 0)
			f_wall = 1;
		else if ((map[line][col] == '1' && f_wall == 1))
			col++;
		else if ((map[line][col] == '0' || is_game_char(map[line][col])) && f_wall == 1)
		{
			if (zero_check(map, line, col))
				col++;
			else
				return (0);
		}
		else if (map[line][col] == '\n'
			&& map[line][col - 1] == '1')
			col++;
		else
			return (0);
	}
	return (1);
}

int	check_map(char **map)
{
	int	map_line;

	map_line = 0;
	if (!first_row_is_valid(map, &map_line, 0))
		return (error_message(1));
	while (map && map[map_line])
	{
		if (!check_row(map, map_line, 0))
			return (error_message(1));
		map_line++;
	}
	return (0);
}
