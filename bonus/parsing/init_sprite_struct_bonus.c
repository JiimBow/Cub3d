/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 12:09:49 by mgarnier         ###   ########.fr       */
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

	mlx->spr = (t_sprite **)malloc(sizeof(t_sprite *) * 1);
	mlx->samourai = mlx_new_image_from_file(mlx->cont, "pics/IDLE.png", &w, &h);
	i = 0;
	x = 0;
	y = 0;
	while (i < 10)
	{
		mlx_get_image_region(mlx->cont, mlx->samourai, x, y, 96, 96, &mlx->spr[0]->samourai_stand[i]);
		x += 96;
		i++;
	}
}

void	put_sprite_on_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->cont, mlx->samourai);
	mlx->samourai = mlx_new_image(mlx->cont, 96, 96);
	mlx_set_image_region(mlx->cont, mlx->samourai, 0, 0, 96, 96, &mlx->spr[0]->samourai_stand[0]);
	mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->samourai, 100, 100, 4, 4, 0);
}
