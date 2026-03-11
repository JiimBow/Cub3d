/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:09:59 by jodone            #+#    #+#             */
/*   Updated: 2026/03/11 11:09:54 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int nbline_in_file(int fd)
{
	int		result;
	char	*tab;

	result = 0;
	while (true)
	{
		tab = get_next_line(fd);
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
	int		map_fd;
	int		i;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = nbline_in_file(map_fd);
	map_copy = ft_calloc(i + 1, sizeof(char *));
	close(map_fd);
	map_fd = open(map_name, O_RDONLY);
	if (map_fd < 0)
		return (NULL);
	i = 0;
	while (true)
	{
		map_copy[i] = get_next_line(map_fd);
		if (!map_copy[i])
			break ;
		i++;
	}
	close(map_fd);
	return (map_copy);
}

int	map_is_valid(char *map_name)
{
	char	**map_copy;
	
	map_copy = copy_map(map_name);
	if (!map_copy)
		return (0);
	if (!check_element(map_copy))
	{
		free_double_ptr(map_copy);
		return (0);
	}
	free_double_ptr(map_copy);
	return (1);
}
