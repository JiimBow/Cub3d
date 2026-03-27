/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:13:12 by jodone            #+#    #+#             */
/*   Updated: 2026/03/27 12:14:29 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_image(t_mlx *mlx, t_text *text, t_map *map)
{
	int	w;
	int	h;

	text->no_text = mlx_new_image_from_file(mlx->cont, map->no_path, &w, &h);
	text->so_text = mlx_new_image_from_file(mlx->cont, map->so_path, &w, &h);
	text->we_text = mlx_new_image_from_file(mlx->cont, map->we_path, &w, &h);
	text->ea_text = mlx_new_image_from_file(mlx->cont, map->ea_path, &w, &h);
	if (!text->no_text || !text->so_text || !text->we_text || !text->ea_text)
		return (error_message(2));
	mlx->buf_no = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_so = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_ea = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	mlx->buf_we = malloc(sizeof(mlx_color) * (TEX_HEIGHT * TEX_WIDTH));
	if (!mlx->buf_no || !mlx->buf_so || !mlx->buf_ea || !mlx->buf_we)
		return (error_message(8));
	return (0);
}
