/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:45:01 by jodone            #+#    #+#             */
/*   Updated: 2026/03/18 17:42:32 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	check_element(t_map *map)
{
	t_list	*elem_lst;
	int		tab_line;
	int		tab_char;
	int		nb_elem;

	elem_lst = element_init_lst();
	tab_line = 0;
	nb_elem = 0;
	while (map->map[tab_line])
	{
		tab_char = 0;
		while (map->map[tab_line][tab_char])
		{
			if (is_space(map->map[tab_line][tab_char]))
			{
				tab_char++;
				continue ;
			}
			else if (nb_elem < 6)
			{
				if (is_element(map->map[tab_line], &elem_lst, map))
				{
					ft_bzero(map->map[tab_line], ft_strlen(map->map[tab_line]));
					nb_elem++;
					break ;
				}
				else
					return (0);
			}
			tab_char++;
		}
		tab_line++;
	}
	return (1);
}
