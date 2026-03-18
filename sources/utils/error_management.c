/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:37:55 by jodone            #+#    #+#             */
/*   Updated: 2026/03/18 19:50:16 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_message(int code)
{
	if (code == 0)
		ft_putstr_fd("Error\nProgram must have only one argument\n", 2);
	else if (code == 1)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error\nTextures value not correct\n", 2);
	return (1);
}
