/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:31:49 by eavilov           #+#    #+#             */
/*   Updated: 2021/11/20 09:19:53 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sstrlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strnstr(const char *str, const char *word, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*word == '\0' || word == NULL)
		return ((char *) str);
	while (str[i] && i < len)
	{
		j = 0;
		while (word[j] == str[i + j] && i + j < len)
		{
			if (word[j + 1] == '\0')
				return ((char *) str + i);
			j++;
		}
		i++;
	}
	return ((char *) NULL);
}
