/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:45:01 by jodone            #+#    #+#             */
/*   Updated: 2026/03/24 09:33:15 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	still_element(t_map *map, t_list **elem_lst, int *nb_elem, int tab_line)
{
	int	tab_char;

	tab_char = 0;
	while (map->old_map[tab_line][tab_char])
	{
		if (is_space(map->old_map[tab_line][tab_char]))
		{
			tab_char++;
			continue ;
		}
		else if (*nb_elem < 6)
		{
			if (is_element(map->old_map[tab_line], elem_lst, map))
			{
				ft_bzero(map->old_map[tab_line],
					ft_strlen(map->old_map[tab_line]));
				(*nb_elem)++;
				break ;
			}
			else
				return (error_message(6));
		}
		tab_char++;
	}
	return (0);
}

int	check_element(t_map *map)
{
	t_list	*elem_lst;
	int		tab_line;
	int		nb_elem;

	elem_lst = element_init_lst();
	tab_line = 0;
	nb_elem = 0;
	while (map->old_map[tab_line])
	{
		if (still_element(map, &elem_lst, &nb_elem, tab_line))
		{
			free_lst(elem_lst);
			return (1);
		}
		tab_line++;
	}
	return (0);
}
