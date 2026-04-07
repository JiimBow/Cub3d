/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:37:55 by jodone            #+#    #+#             */
/*   Updated: 2026/04/07 17:26:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	error_message(int code)
{
	if (code == 0)
		ft_putstr_fd("Error\nProgram must have only one argument\n", 2);
	else if (code == 1)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error\nTextures didn't load well\n", 2);
	else if (code == 3)
		ft_putstr_fd("Error\nMap extension is not valid\n", 2);
	else if (code == 4)
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
	else if (code == 5)
		ft_putstr_fd("Error\nColor values aren't correct\n", 2);
	else if (code == 6)
		ft_putstr_fd("Error\nGiven elements aren't correct\n", 2);
	else if (code == 7)
		ft_putstr_fd("Error\nNo player position given\n", 2);
	else if (code == 8)
		ft_putstr_fd("Error\nAllocation memory failed\n", 2);
	else if (code == 9)
		ft_putstr_fd("Error\nMlx_init failed\n", 2);
	return (1);
}
