/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:16 by jodone            #+#    #+#             */
/*   Updated: 2026/03/26 10:33:01 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
	#include "cub3d_bonus.h"
#else
	#include "cub3d.h"
#endif

static int	add_texture(t_map *map, char *map_line, int i)
{
	char	*tmp_path;

	tmp_path = ft_substr(map_line, 1, ft_strlen(map_line) - 1);
	if (!ft_strncmp(map_line, "F", 1) || !ft_strncmp(map_line, "C", 1))
		while (tmp_path[i] && !ft_isdigit(tmp_path[i]))
			i++;
	else
		while (tmp_path[i] && tmp_path[i] != '.')
			i++;
	if (tmp_path[i] == '\0')
	{
		free(tmp_path);
		return (0);
	}
	tmp_path[ft_strlen(tmp_path) - 1] = '\0';
	if (!ft_strncmp(map_line, "NO", 2))
		map->no_path = ft_strdup(tmp_path + i);
	else if (!ft_strncmp(map_line, "SO", 2))
		map->so_path = ft_strdup(tmp_path + i);
	else if (!ft_strncmp(map_line, "WE", 2))
		map->we_path = ft_strdup(tmp_path + i);
	else if (!ft_strncmp(map_line, "EA", 2))
		map->ea_path = ft_strdup(tmp_path + i);
	else if (!ft_strncmp(map_line, "F", 1))
		map->f_value = ft_strdup(tmp_path + i);
	else if (!ft_strncmp(map_line, "C", 1))
		map->c_value = ft_strdup(tmp_path + i);
	free(tmp_path);
	return (1);
}

static int	first_node(t_list **elem_lst, char *content, int len_content)
{
	t_list	*supp;

	supp = NULL;
	if (ft_strncmp((*elem_lst)->content, content, len_content) == 0)
	{
		supp = *elem_lst;
		*elem_lst = supp->next;
		free(supp);
		return (1);
	}
	return (0);
}

static void	remove_node(t_list **elem_lst, char *content)
{
	t_list	*supp;
	t_list	*tmp;
	int		len_content;

	supp = NULL;
	len_content = ft_strlen(content);
	if (first_node(elem_lst, content, len_content))
		return ;
	tmp = *elem_lst;
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->next->content, content, len_content) == 0)
		{
			supp = tmp->next;
			break ;
		}
		tmp = tmp->next;
	}
	tmp->next = supp->next;
	free(supp);
}

int	is_element(char *map_line, t_list **elem_lst, t_map *map)
{
	t_list	*tmp;

	tmp = *elem_lst;
	while (tmp)
	{
		if (ft_strncmp(map_line, tmp->content, ft_strlen(tmp->content)) == 0)
		{
			if (!add_texture(map, map_line, 0))
				return (0);
			remove_node(elem_lst, tmp->content);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
