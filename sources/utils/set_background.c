/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:07:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/13 11:13:16 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image	set_background(t_mlx mlx)
{
	mlx_image	image;
	int			x;
	int			y;

	image = mlx_new_image(mlx.cont, mlx.info.width, mlx.info.height);
	y = 0;
	while (y < mlx.info.height)
	{
		x = 0;
		while (y < mlx.info.height / 2 && x < mlx.info.width)
		{
			mlx_set_image_pixel(mlx.cont, image, x, y, SKY);
			x++;
		}
		x = 0;
		while (y >= mlx.info.height / 2
			&& y < mlx.info.height && x < mlx.info.width)
		{
			mlx_set_image_pixel(mlx.cont, image, x, y, GROUND);
			x++;
		}
		y++;
	}
	return (image);
}
