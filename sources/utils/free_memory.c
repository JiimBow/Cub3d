/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:05:01 by jodone            #+#    #+#             */
/*   Updated: 2026/03/23 16:44:38 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_map(t_map *map)
{
	free_double_ptr(map->old_map);
	free(map->c_value);
	free(map->f_value);
	free(map->ea_path);
	free(map->no_path);
	free(map->so_path);
	free(map->we_path);
}

void	free_all(t_map *map)
{
	free_map(map);
}
