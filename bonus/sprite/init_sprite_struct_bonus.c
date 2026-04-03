/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/04/03 15:20:41 by mgarnier         ###   ########.fr       */
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
	mlx->samourai[0] = mlx_new_image_from_file(mlx->cont, "./pics/IDLE.png", &w, &h);
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
	mlx->samourai[1] = mlx_new_image_from_file(mlx->cont, "./pics/ATTACK 1.png", &w, &h);
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
