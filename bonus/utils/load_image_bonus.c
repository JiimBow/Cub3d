/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:49:26 by jodone            #+#    #+#             */
/*   Updated: 2026/04/03 23:46:07 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	load_color_buffer(t_mlx *mlx)
{
	mlx->buf_no = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_so = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_ea = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_we = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_do = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	if (!mlx->buf_no || !mlx->buf_so || !mlx->buf_ea || !mlx->buf_we
		|| !mlx->buf_do)
		return (error_message(8));
	return (0);
}

int	load_image(t_mlx *mlx, t_text *text, t_map *map)
{
	int	w;
	int	h;

	text->no_text = mlx_new_image_from_file(mlx->cont, map->no_path, &w, &h);
	text->so_text = mlx_new_image_from_file(mlx->cont, map->so_path, &w, &h);
	text->we_text = mlx_new_image_from_file(mlx->cont, map->we_path, &w, &h);
	text->ea_text = mlx_new_image_from_file(mlx->cont, map->ea_path, &w, &h);
	text->do_text = mlx_new_image_from_file(mlx->cont,
			"./pics/door.png", &w, &h);
	mlx->heart = mlx_new_image_from_file(mlx->cont,
			"pics/heart.png", &w, &h);
	mlx->heart_broken = mlx_new_image_from_file(mlx->cont,
			"pics/heart_broken.png", &w, &h);
	mlx->dead1 = mlx_new_image_from_file(mlx->cont,
			"pics/skull1.png", &w, &h);
	mlx->dead2 = mlx_new_image_from_file(mlx->cont,
			"pics/skull2.png", &w, &h);
	if (!text->no_text || !text->so_text || !text->we_text || !text->ea_text
		|| !text->do_text || !mlx->heart || !mlx->heart_broken
		|| !mlx->dead1 || !mlx->dead2)
		return (error_message(2));
	if (load_color_buffer(mlx))
		return (1);
	return (0);
}
