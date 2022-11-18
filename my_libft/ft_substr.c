/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:47:04 by eavilov           #+#    #+#             */
/*   Updated: 2021/12/16 10:47:39 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t			h;
	char			*dest;

	if (!src)
		return (NULL);
	if (len > ft_strlen(src))
		len = ft_strlen(src);
	dest = malloc(sizeof (char) * len + 1);
	if (!dest)
		return (NULL);
	h = 0;
	while (h < len && start < ft_strlen(src))
	{
		dest[h] = src[start + h];
		h++;
	}
	dest[h] = '\0';
	return (dest);
}
