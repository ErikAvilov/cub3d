/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:32:50 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/12 08:51:43 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrdup(char const *src, char c)
{
	int		index;
	char	*array;
	int		y;

	index = 0;
	y = 0;
	while (src[index] && src[index] != c)
		index++;
	array = malloc (sizeof (char) * (index + 1));
	if (!array)
		return (NULL);
	while (y < index)
	{
		array[y] = src[y];
		y++;
	}
	array[y] = '\0';
	return (array);
}

int	countchar(char const *s, char c)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (s[k])
	{
		if ((k == 0) && s[0] != c)
			count++;
		else if (s[k] != c && s[k - 1] == c)
			count++;
		k++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = countchar(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			result[i] = ft_strrdup(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}
