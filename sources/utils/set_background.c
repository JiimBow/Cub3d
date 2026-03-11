/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:07:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 15:32:33 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image	set_background(t_mlx mlx)
{
	mlx_image	image;
	int			x;
	int			y;

	image = mlx_new_image(mlx.context, mlx.info.width, mlx.info.height);
	y = 0;
	while (y < mlx.info.height)
	{
		x = 0;
		while (y < mlx.info.height / 2 && x < mlx.info.width)
		{
			mlx_set_image_pixel(mlx.context, image, x, y, (mlx_color){.rgba = 0x5a96d7cc});
			x++;
		}
		x = 0;
		while (y >= mlx.info.height / 2 && y < mlx.info.height && x < mlx.info.width)
		{
			mlx_set_image_pixel(mlx.context, image, x, y, (mlx_color){.rgba = 0xa2a2a2cc});
			x++;
		}
		y++;
	}
	return (image);
}
