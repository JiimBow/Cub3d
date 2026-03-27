/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:53:17 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/27 11:04:57 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_valid(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result < 0 || result > 255)
			return (0);
		i++;
	}
	return (1);
}
