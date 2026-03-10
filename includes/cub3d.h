/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:59 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/10 13:59:48 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "mlx.h"
# include "mlx_extended.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_mlx
{
	mlx_context	context;
	mlx_window	window;
}	t_mlx;

int	error_message(int code);

int	main();