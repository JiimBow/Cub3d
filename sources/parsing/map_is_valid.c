/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:09:59 by jodone            #+#    #+#             */
/*   Updated: 2026/03/19 10:18:42 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	nbline_in_file(int fd, int *max_len)
{
	int		result;
	char	*tab;
	int		tab_len;

	result = 0;
	while (true)
	{
		tab = get_next_line(fd);
		tab_len = ft_strlen(tab);
		if (tab_len > (*max_len))
			(*max_len) = tab_len;
		if (!tab)
			break ;
		result++;
		free(tab);
	}
	return (result);
}

static char	**copy_map(char *map_name)
{
	char	**map_copy;
	char	*tab_line;
	int		map_fd;
	int		i;
	int		max_len;

	max_len = 0;
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = nbline_in_file(map_fd, &max_len);
	map_copy = ft_calloc(i + 1, sizeof(char *));
	close(map_fd);
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = 0;
	while (true)
	{
		tab_line = get_next_line(map_fd);
		if (!tab_line)
		{
			map_copy[i] = NULL;
			break ;
		}
		map_copy[i] = malloc((max_len + 1) * sizeof(char));
		ft_memset(map_copy[i], ' ', max_len);
		ft_strlcpy(map_copy[i], tab_line, ft_strlen(tab_line) + 1);
		free(tab_line);
		i++;
	}
	close(map_fd);
	return (map_copy);
}

int	map_is_valid(char *file, t_map *map)
{
	map->map = copy_map(file);
	if (!map->map)
		return (0);
	if (!check_element(map))
	{
		free_double_ptr(map->map);
		return (0);
	}
	if (!check_map(map->map))
	{
		free_double_ptr(map->map);
		return (0);
	}
	// free_double_ptr(map->map);
	return (1);
}
