/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:16 by jodone            #+#    #+#             */
/*   Updated: 2026/03/19 17:43:10 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_texture(t_map *map, char *map_line)
{
	char	*tmp_path;

	tmp_path = ft_substr(map_line, 1, ft_strlen(map_line) - 1);
	if (!ft_strncmp(map_line, "F", 1) || !ft_strncmp(map_line, "C", 1))
		while (*tmp_path == ' ')
			tmp_path++;
	else
		while (*tmp_path != '.')
			tmp_path++;
	tmp_path[ft_strlen(tmp_path) - 1] = '\0';
	if (!ft_strncmp(map_line, "NO", 2))
		map->no_path = ft_strdup(tmp_path);
	else if (!ft_strncmp(map_line, "SO", 2))
		map->so_path = ft_strdup(tmp_path);
	else if (!ft_strncmp(map_line, "WE", 2))
		map->we_path = ft_strdup(tmp_path);
	else if (!ft_strncmp(map_line, "EA", 2))
		map->ea_path = ft_strdup(tmp_path);
	else if (!ft_strncmp(map_line, "F", 1))
		map->f_value = ft_strdup(tmp_path);
	else if (!ft_strncmp(map_line, "C", 1))
		map->c_value = ft_strdup(tmp_path);
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
			add_texture(map, map_line);
			remove_node(elem_lst, tmp->content);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_list	*element_init_lst(void)
{
	t_list	*elem_lst;

	elem_lst = NULL;
	ft_lstadd_back(&elem_lst, ft_lstnew("NO"));
	ft_lstadd_back(&elem_lst, ft_lstnew("SO"));
	ft_lstadd_back(&elem_lst, ft_lstnew("WE"));
	ft_lstadd_back(&elem_lst, ft_lstnew("EA"));
	ft_lstadd_back(&elem_lst, ft_lstnew("F"));
	ft_lstadd_back(&elem_lst, ft_lstnew("C"));
	return (elem_lst);
}
