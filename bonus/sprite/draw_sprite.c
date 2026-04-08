/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:41:01 by jodone            #+#    #+#             */
/*   Updated: 2026/04/08 14:03:29 by mgarnier         ###   ########.fr       */
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
	mlx->s_frame %= 90;
	draw->i = mlx->s_frame / SP1_FRAME;
	while (y < draw->total)
	{
		d = (y + draw->start_y) * 256 - SCREEN_H * 128 + draw->size * 128;
		tex_y = ((d * SPR_HEIGHT / draw->size) / 256);
		color = mlx->samourai_stand[draw->i][tex_y * SPR_WIDTH + tex_x];
		if (color.a >= 128)
			mlx_set_image_pixel(mlx->cont, mlx->sprite, x,
				y + draw->start_y, color);
		y++;
	}
}

static void	put_sprite_pixel2(t_mlx *mlx, t_draw *draw, int tex_x, int x)
{
	int			y;
	int			d;
	int			tex_y;
	mlx_color	color;

	y = 0;
	mlx->s_frame %= 49;
	draw->i = mlx->s_frame / SP2_FRAME;
	while (y < draw->total)
	{
		d = (y + draw->start_y) * 256 - SCREEN_H * 128 + draw->size * 128;
		tex_y = ((d * SPR_HEIGHT / draw->size) / 256);
		color = mlx->samourai_attack[draw->i][tex_y * SPR_WIDTH + tex_x];
		if (color.a >= 128)
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
		{
			if (mlx->tempo == 1 && mlx->i == mlx->sprite_count - 1)
				put_sprite_pixel2(mlx, draw, tex_x, x);
			else
				put_sprite_pixel(mlx, draw, tex_x, x);
		}
		x++;
	}
}

static void	set_sort_sprites(t_mlx *mlx)
{
	static double	px = 0.0;
	static double	py = 0.0;

	if (px != mlx->pos_x || py != mlx->pos_y)
	{
		px = mlx->pos_x;
		py = mlx->pos_y;
		sort_sprites(mlx, mlx->spr);
	}
}

int	draw_sprites(t_mlx *mlx, double *zbuffer)
{
	double			tx;
	double			ty;
	t_draw			draw;

	mlx->i = 0;
	set_sort_sprites(mlx);
	while (mlx->i < mlx->sprite_count)
	{
		if (get_trans(mlx, mlx->spr[mlx->i], &tx, &ty) == 1)
		{
			mlx->i++;
			continue ;
		}
		draw.screen_x = (int)(SCREEN_W / 2 * (1 + tx / ty));
		draw.size = abs((int)(SCREEN_H / ty)) / 0.7;
		def_start_end_x(&draw);
		def_start_end_y(&draw);
		set_pixel_put(mlx, &draw, ty, zbuffer);
		mlx->i++;
	}
	return (0);
}
