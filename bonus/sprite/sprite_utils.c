/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:45:16 by jodone            #+#    #+#             */
/*   Updated: 2026/04/01 16:02:27 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_trans(t_mlx *mlx, t_sprite spr, double *transx, double *transy)
{
	double	spritex;
	double	spritey;
	double	inv_det;

	spritex = spr.pos_x - mlx->pos_x;
	spritey = spr.pos_y - mlx->pos_y;
	inv_det = 1.0 / (mlx->plane_x * mlx->dir_y - mlx->dir_x * mlx->plane_y);
	*transx = inv_det * (mlx->dir_y * spritex - mlx->dir_x * spritey);
	*transy = inv_det * (-mlx->plane_y * spritex + mlx->plane_x * spritey);
	if (*transy <= 0)
		return (1);
	return (0);
}

void	def_start_end_x(t_draw *draw)
{
	draw->start_x = draw->screen_x - draw->size / 2;
	if (draw->start_x < 0)
		draw->start_x = 0;
	draw->end_x = draw->screen_x + draw->size / 2;
	if (draw->end_x >= SCREEN_W)
		draw->end_x = SCREEN_W - 1;
}

void	def_start_end_y(t_draw *draw)
{
	draw->start_y = -draw->size / 2 + SCREEN_H / 2;
	if (draw->start_y < 0)
		draw->start_y = 0;
	draw->end_y = draw->size / 2 + SCREEN_H / 2;
	if (draw->end_y >= SCREEN_H)
		draw->end_y = SCREEN_H - 1;
}
