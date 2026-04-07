/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:09:59 by jodone            #+#    #+#             */
/*   Updated: 2026/04/07 18:14:30 by mgarnier         ###   ########.fr       */
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

static int	get_map_from_file(int map_fd, char **map_copy, int max_len)
{
	char	*tab_line;
	int		i;
	int		signal;

	signal = 0;
	i = 0;
	while (true)
	{
		tab_line = get_next_line(map_fd);
		if (!tab_line)
			break ;
		map_copy[i] = malloc((max_len + 1) * sizeof(char));
		if (map_copy[i])
		{
			ft_memset(map_copy[i], ' ', max_len);
			ft_strlcpy(map_copy[i], tab_line, ft_strlen(tab_line) + 1);
			i++;
		}
		else
			signal = 1;
		free(tab_line);
	}
	map_copy[i] = NULL;
	return (signal);
}

static char	**copy_map(char *map_name)
{
	char	**map_copy;
	int		map_fd;
	int		i;
	int		max_len;

	max_len = 0;
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = nbline_in_file(map_fd, &max_len);
	close(map_fd);
	map_copy = ft_calloc(i + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0 || get_map_from_file(map_fd, map_copy, max_len))
	{
		if (map_fd >= 0)
			close(map_fd);
		free_double_ptr(map_copy);
		return (NULL);
	}
	close(map_fd);
	return (map_copy);
}

static int	check_filename(char *file, char *ext)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(file);
	if (len < 5)
		return (error_message(4));
	while (file && file[i] && file[0] != '.')
	{
		if (file[i] == ext[0])
		{
			j = 0;
			while (file[i] && file[i] == ext[j])
			{
				i++;
				j++;
			}
			if (file[i] == '\0')
				return (0);
		}
		i++;
	}
	return (error_message(3));
}

int	map_is_not_valid(char *file, t_map *map)
{
	char	*copy_name;

	ft_bzero(map, sizeof(t_map));
	copy_name = ft_strrchr(file, '/') + 1;
	if (check_filename(copy_name, ".cub"))
		return (1);
	map->old_map = copy_map(file);
	if (!map->old_map)
		return (error_message(4));
	if (check_element(map))
	{
		free_map(map);
		return (1);
	}
	if (check_map(map->old_map))
	{
		free_map(map);
		return (1);
	}
	map->map = map->old_map;
	while (map->map[0][0] == '\0' || map->map[0][0] == '\n')
		map->map++;
	return (0);
}
