/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 22:58:24 by mgarnier         ###   ########.fr       */
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

void	set_sprites(t_mlx *mlx, t_wall *ray, int column)
{
	mlx_color	buf[SCREEN_H];
	double		step;
	int			x;
	int			y;

	x = 0;
	y = 48;
	step = 1.0 * SPR_HEIGHT / ray->side_dist_x;
	while (x < SPR_HEIGHT)
	{
		buf[x] = mlx->spr[0].samourai_stand[0][x * SPR_WIDTH + y];
		x++;
	}
	mlx_set_image_region(mlx->cont, mlx->sprite, column, SCREEN_H / 2, 1, SPR_HEIGHT, buf);
}

void	get_sprites(t_mlx *mlx, t_wall *ray, int x)
{
	while (true)
	{
		if (mlx->s_map->map[ray->map_y][ray->map_x] == '2')
			set_sprites(mlx, ray, x);
		if (ray->side_dist_x < 0 || ray->side_dist_y < 0)
			break ;
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x -= ray->delta_dist_x;
			ray->map_x -= ray->step_x;
		}
		else
		{
			ray->side_dist_y -= ray->delta_dist_y;
			ray->map_y -= ray->step_y;
		}
	}
}
