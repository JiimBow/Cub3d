/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:59:30 by jodone            #+#    #+#             */
/*   Updated: 2026/04/08 09:52:38 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			result = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		result = (char *)&s[i];
	return (result);
}
