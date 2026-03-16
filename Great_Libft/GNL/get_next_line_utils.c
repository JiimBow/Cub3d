/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:59:36 by jodone            #+#    #+#             */
/*   Updated: 2026/03/16 14:10:23 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	i;

	if ((size_t) - 1 < size * nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	lensrc;

	if (!s)
		return (NULL);
	lensrc = gnl_strlen(s);
	if (start >= lensrc)
	{
		result = gnl_calloc(1, 1);
		return (result);
	}
	if (len > lensrc - start)
		len = lensrc - start;
	result = gnl_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	lensrc = 0;
	while (s[start] && lensrc < len)
		result[lensrc++] = s[start++];
	result[lensrc] = '\0';
	return (result);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		lens1;
	char	*tab;
	int		i;

	if (!s1)
	{
		tab = gnl_substr(s2, 0, gnl_strlen(s2));
		return (tab);
	}
	if (!s2)
		return (s1);
	lens1 = gnl_strlen(s1);
	tab = gnl_calloc((lens1 + gnl_strlen(s2)) + 1, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
		tab[lens1++] = s2[i++];
	tab[lens1] = '\0';
	free(s1);
	return (tab);
}
