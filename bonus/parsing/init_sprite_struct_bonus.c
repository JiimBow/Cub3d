/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 16:17:47 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	set_sprite_start(t_mlx *mlx)
{
	int			w;
	int			h;
	int			i;
	int			x;
	int			y;

	// mlx->spr = (t_sprite **)malloc(sizeof(t_sprite *) * 1);
	// mlx->spr[0] = malloc(sizeof(t_sprite));
	mlx->samourai = mlx_new_image_from_file(mlx->cont, "pics/IDLE.png", &w, &h);
	i = 0;
	x = 0;
	while (i < 10)
	{
		mlx_get_image_region(mlx->cont, mlx->samourai[0], x, 0, 96, 96, mlx->spr->samourai_stand[i]);
		x += 96;
		i++;
	}
	mlx->samourai[1] = mlx_new_image_from_file(mlx->cont, "pics/ATTACK 1.png", &w, &h);
	i = 0;
	x = 0;
	while (i < 7)
	{
		mlx_get_image_region(mlx->cont, mlx->samourai[1], x, 0, 96, 96, mlx->spr->samourai_attack[i]);
		x += 96;
		i++;
	}
	mlx->frame = 0;
}

void	put_sprite_on_window(t_mlx *mlx)
{
	int	i;

	mlx->frame++;
	mlx->frame %= 90;
	i = mlx->frame / 10;
	mlx->samourai[0] = mlx_new_image(mlx->cont, 96, 96);
	mlx_set_image_region(mlx->cont, mlx->samourai[0], 0, 0, 96, 96, mlx->spr->samourai_stand[i]);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->samourai[0], 100, 100, 4, 4, 0);
	i = mlx->frame / 15;
	mlx->samourai[1] = mlx_new_image(mlx->cont, 96, 96);
	mlx_set_image_region(mlx->cont, mlx->samourai[1], 0, 0, 96, 96, mlx->spr->samourai_attack[i]);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->samourai[1], 200, 200, 4, 4, 0);
}
