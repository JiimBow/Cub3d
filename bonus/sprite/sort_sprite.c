/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:04:58 by jodone            #+#    #+#             */
/*   Updated: 2026/04/01 11:45:12 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static double	distance_calcul(t_mlx *mlx, t_sprite sprite)
{
	double	distx;
	double	disty;
	double	dist_diff;

	distx = (sprite.pos_x - mlx->pos_x);
	disty = (sprite.pos_y - mlx->pos_y);
	dist_diff = distx * distx + disty * disty;
	return (dist_diff);
}

void	sort_sprites(t_mlx *mlx, t_sprite *spr, t_sprite *new_spr)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < mlx->sprite_count)
	{
		new_spr[i] = spr[i];
		new_spr[i].dist = distance_calcul(mlx, spr[i]);
		i++;
	}
	i = 0;
	while (i < mlx->sprite_count - 1)
	{
		if (new_spr[i].dist < new_spr[i + 1].dist)
		{
			tmp = new_spr[i];
			new_spr[i] = new_spr[i + 1];
			new_spr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
