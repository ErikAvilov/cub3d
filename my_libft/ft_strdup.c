/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:51:13 by eavilov           #+#    #+#             */
/*   Updated: 2021/12/13 19:01:38 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*array;
	int		y;

	i = 0;
	y = 0;
	while (src[i])
		i++;
	array = malloc (sizeof (char) * (i + 1));
	if (!array)
		return (NULL);
	while (y < i)
	{
		array[y] = src[y];
		y++;
	}
	array[y] = '\0';
	return (array);
}
