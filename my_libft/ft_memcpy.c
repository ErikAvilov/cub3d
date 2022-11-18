/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:15:08 by eavilov           #+#    #+#             */
/*   Updated: 2021/12/16 09:19:54 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *restrict dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dest);
}
