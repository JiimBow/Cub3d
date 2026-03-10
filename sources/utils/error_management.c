/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:37:55 by jodone            #+#    #+#             */
/*   Updated: 2026/03/10 14:01:14 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_message(int code)
{
	if (code == 0)
		ft_putstr_fd("Error\nProgram must have only one argument\n", 2);
	return (1);
}
