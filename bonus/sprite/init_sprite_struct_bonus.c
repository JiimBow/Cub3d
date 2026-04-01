/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/04/01 11:56:00 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	set_sprite_start(t_mlx *mlx)
{
	int			w;
	int			h;
	int			i;
	int			x;

	mlx->sprite = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
	mlx->samourai[0] = mlx_new_image_from_file(mlx->cont, "pics/IDLE.png", &w, &h);
	if (!mlx->samourai[0])
		return (error_message(2));
	i = 0;
	x = 0;
	while (i < 10)
	{
		mlx_get_image_region(mlx->cont, mlx->samourai[0], x, 0, SPR_WIDTH, SPR_HEIGHT, mlx->spr->samourai_stand[i]);
		x += SPR_WIDTH;
		i++;
	}
	mlx->samourai[1] = mlx_new_image_from_file(mlx->cont, "pics/ATTACK 1.png", &w, &h);
	if (!mlx->samourai[1])
		return (error_message(2));
	i = 0;
	x = 0;
	while (i < 7)
	{
		mlx_get_image_region(mlx->cont, mlx->samourai[1], x, 0, SPR_WIDTH, SPR_HEIGHT, mlx->spr->samourai_attack[i]);
		x += SPR_WIDTH;
		i++;
	}
	mlx->frame = 0;
	return (0);
}

void	put_sprite_on_window(t_mlx *mlx)
{
	int	i;

	mlx->frame++;
	mlx->frame %= 90;
	i = mlx->frame / 10;
	mlx->samourai[0] = mlx_new_image(mlx->cont, SPR_WIDTH, SPR_HEIGHT);
	mlx_set_image_region(mlx->cont, mlx->samourai[0], 0, 0, SPR_WIDTH, SPR_HEIGHT, mlx->spr->samourai_stand[i]);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->samourai[0], SCREEN_W / 2 + SPR_WIDTH * 2, SCREEN_H / 2 - SPR_HEIGHT * 2, 4, 4, 0);
	i = mlx->frame / 15;
	mlx->samourai[1] = mlx_new_image(mlx->cont, SPR_WIDTH, SPR_HEIGHT);
	mlx_set_image_region(mlx->cont, mlx->samourai[1], 0, 0, 96, 96, mlx->spr->samourai_attack[i]);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->samourai[1], SCREEN_W / 4 - SPR_WIDTH * 2, SCREEN_H / 2 - SPR_HEIGHT * 2, 4, 4, 0);
}

void	draw_sprites(t_mlx *mlx, double *zbuffer)
{
	int			i;
	double		sx;
	double		sy;
	double		inv_det;
	double		tx;
	double		ty;
	int			screen_x;
	int			size;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	int			x;
	int			tex_x;
	int			tex_y;
	mlx_color	buf[SCREEN_H];
	t_sprite	*sorted_sprites;

	i = 0;
	sorted_sprites = malloc(mlx->sprite_count * sizeof(t_sprite));
	sort_sprites(mlx, mlx->spr, sorted_sprites);
	while (i < mlx->sprite_count)
	{
		sx = sorted_sprites[i].pos_x - mlx->pos_x;
		sy = sorted_sprites[i].pos_y - mlx->pos_y;
		inv_det = 1.0 / (mlx->plane_x * mlx->dir_y - mlx->dir_x * mlx->plane_y);
		tx = inv_det * (mlx->dir_y * sx - mlx->dir_x * sy);
		ty = inv_det * (-mlx->plane_y * sx + mlx->plane_x * sy);
		if (ty <= 0)
		{
			i++;
			continue;
		}
		screen_x = (int)(SCREEN_W / 2 * (1 + tx / ty));
		size = abs((int)(SCREEN_H / ty));
		start_y = -size / 2 + SCREEN_H / 2;
		if (start_y < 0)
			start_y = 0;
		end_y = size / 2 + SCREEN_H / 2;
		if (end_y >= SCREEN_H)
			end_y = SCREEN_H - 1;
		start_x = screen_x - size / 2;
		if (start_x < 0)
			start_x = 0;
		end_x = screen_x + size / 2;
		if (end_x >= SCREEN_W)
			end_x = SCREEN_W - 1;
		x = start_x;
		int k = 0;
		while (k < SCREEN_H)
			buf[k++] = (mlx_color){0};
		while (x < end_x)
		{
				tex_x = (x - (-size / 2 + screen_x)) * SPR_WIDTH / size;
				int y = 0;
				int	total = end_y - start_y;
				if (ty < zbuffer[x])
				{
					while (y < total)
					{
						int	d = (y + start_y) * 256 - SCREEN_H * 128 + size * 128;
						tex_y = ((d * SPR_HEIGHT / size) / 256);
						buf[y] = mlx->spr[0].samourai_stand[0][tex_y * SPR_WIDTH + tex_x];
						y++;
					}
					mlx_set_image_region(mlx->cont, mlx->sprite,
						x, start_y, 1, end_y - start_y, buf);
				}
			x++;
		}
		i++;
	}
}
