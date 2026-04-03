/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:46:11 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/03 17:20:42 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	destroy_wall_image(t_mlx *mlx)
{
	if (mlx->background)
		mlx_destroy_image(mlx->cont, mlx->background);
	if (mlx->s_text->no_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->no_text);
	if (mlx->s_text->so_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->so_text);
	if (mlx->s_text->we_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->we_text);
	if (mlx->s_text->ea_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->ea_text);
	if (mlx->s_text->do_text)
		mlx_destroy_image(mlx->cont, mlx->s_text->do_text);
	if (mlx->wall)
		mlx_destroy_image(mlx->cont, mlx->wall);
}

static void	destroy_sprite_image(t_mlx *mlx)
{
	if (mlx->minimap)
		mlx_destroy_image(mlx->cont, mlx->minimap);
	if (mlx->samourai[0])
		mlx_destroy_image(mlx->cont, mlx->samourai[0]);
	if (mlx->samourai[1])
		mlx_destroy_image(mlx->cont, mlx->samourai[1]);
	if (mlx->sprite)
		mlx_destroy_image(mlx->cont, mlx->sprite);
	if (mlx->heart)
		mlx_destroy_image(mlx->cont, mlx->heart);
	if (mlx->heart_broken)
		mlx_destroy_image(mlx->cont, mlx->heart_broken);
	if (mlx->dead1)
		mlx_destroy_image(mlx->cont, mlx->dead1);
	if (mlx->dead2)
		mlx_destroy_image(mlx->cont, mlx->dead2);
}

void	destroy_image_window_context(t_mlx *mlx, t_map *map)
{
	free_color(mlx);
	destroy_wall_image(mlx);
	destroy_sprite_image(mlx);
	if (mlx->buf_do)
		free(mlx->buf_do);
	if (mlx->win)
		mlx_destroy_window(mlx->cont, mlx->win);
	if (mlx->cont)
		mlx_destroy_context(mlx->cont);
	if (mlx->spr)
		free(mlx->spr);
	if (mlx->s_door)
		free(mlx->s_door);
	if (mlx->clear)
		free(mlx->clear);
	free_map(map);
}
