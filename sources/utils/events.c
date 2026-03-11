/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:06:03 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 15:06:18 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->context);
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}
