/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:59 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 15:16:00 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "mlx.h"
# include "mlx_extended.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_mlx
{
	mlx_context				context;
	mlx_window				window;
	mlx_window_create_info	info;
	struct timeval			last_time;
	double					delta;
	double					fps;
	double					fps_timer;
	double					frame_count;
}	t_mlx;

int			error_message(int code);
void		update_frame(void *param);
void		window_hook(int event, void *par);
void		key_hook(int key, void *param);
mlx_image	set_background(t_mlx mlx);
void		init_mlx_struct(t_mlx *mlx);
