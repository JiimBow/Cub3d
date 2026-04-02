/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:41:01 by jodone            #+#    #+#             */
/*   Updated: 2026/04/01 21:48:05 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	put_sprite_pixel(t_mlx *mlx, t_draw *draw, int tex_x, int x)
{
	int			y;
	int			d;
	int			tex_y;
	mlx_color	color;

	y = 0;
	mlx->s_frame %= 60;
	draw->i = mlx->s_frame / 10;
	while (y < draw->total)
	{
		d = (y + draw->start_y) * 256 - SCREEN_H * 128 + draw->size * 128;
		tex_y = ((d * SPR_HEIGHT / draw->size) / 256);
		color = mlx->spr[0].samourai_stand[draw->i][tex_y * SPR_WIDTH + tex_x];
		if (color.a != 0)
			mlx_set_image_pixel(mlx->cont, mlx->sprite, x,
				y + draw->start_y, color);
		y++;
	}
}

static void	set_pixel_put(t_mlx *mlx, t_draw *draw, double ty, double *zbuffer)
{
	int	x;
	int	tex_x;

	x = draw->start_x;
	while (x < draw->end_x)
	{
		tex_x = (x - (-draw->size / 2 + draw->screen_x))
			* SPR_WIDTH / draw->size;
		draw->total = draw->end_y - draw->start_y;
		if (ty < zbuffer[x])
			put_sprite_pixel(mlx, draw, tex_x, x);
		x++;
	}
}

void	draw_sprites(t_mlx *mlx, double *zbuffer)
{
	int			i;
	double		tx;
	double		ty;
	t_sprite	*sorted_sprites;
	t_draw		draw;

	i = 0;
	sorted_sprites = malloc(mlx->sprite_count * sizeof(t_sprite));
	sort_sprites(mlx, mlx->spr, sorted_sprites);
	while (i < mlx->sprite_count)
	{
		if (get_trans(mlx, sorted_sprites[i], &tx, &ty) == 1)
		{
			i++;
			continue ;
		}
		draw.screen_x = (int)(SCREEN_W / 2 * (1 + tx / ty));
		draw.size = abs((int)(SCREEN_H / ty)) / 0.6;
		def_start_end_x(&draw);
		def_start_end_y(&draw);
		set_pixel_put(mlx, &draw, ty, zbuffer);
		i++;
	}
	free(sorted_sprites);
}
