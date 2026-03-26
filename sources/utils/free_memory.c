/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:05:01 by jodone            #+#    #+#             */
/*   Updated: 2026/03/26 11:06:47 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "cub3d_bonus.h"
#else
# include "cub3d.h"
#endif

void	free_color(t_mlx *mlx)
{
	if (mlx->buf_no)
		free(mlx->buf_no);
	if (mlx->buf_so)
		free(mlx->buf_so);
	if (mlx->buf_ea)
		free(mlx->buf_ea);
	if (mlx->buf_we)
		free(mlx->buf_we);
}

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
	if (map->old_map)
		free_double_ptr(map->old_map);
	if (map->c_value)
		free(map->c_value);
	if (map->f_value)
		free(map->f_value);
	if (map->ea_path)
		free(map->ea_path);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
