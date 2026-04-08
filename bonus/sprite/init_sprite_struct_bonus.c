/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_struct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:35:33 by jodone            #+#    #+#             */
/*   Updated: 2026/04/08 13:57:05 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	set_sprite_start(t_mlx *mlx, int nb_frame, int spr_x)
{
	int			w;
	int			h;

	mlx->sprite = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
	mlx->samourai[0] = mlx_new_image_from_file(mlx->cont,
			"./pics/STAND.png", &w, &h);
	if (!mlx->samourai[0])
		return (error_message(2));
	mlx->samourai[1] = mlx_new_image_from_file(mlx->cont,
			"./pics/ATTACK.png", &w, &h);
	if (!mlx->samourai[1])
		return (error_message(2));
	while (nb_frame < SP1_FRAME || nb_frame < SP2_FRAME)
	{
		if (nb_frame < SP1_FRAME)
			mlx_get_image_region(mlx->cont, mlx->samourai[0], spr_x, 0,
				SPR_WIDTH, SPR_HEIGHT, mlx->samourai_stand[nb_frame]);
		if (nb_frame < SP2_FRAME)
			mlx_get_image_region(mlx->cont, mlx->samourai[1], spr_x, 0,
				SPR_WIDTH, SPR_HEIGHT, mlx->samourai_attack[nb_frame]);
		spr_x += SPR_WIDTH;
		nb_frame++;
	}
	mlx->frame = 0;
	return (0);
}
