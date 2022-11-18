/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:55:49 by eavilov           #+#    #+#             */
/*   Updated: 2021/11/12 17:53:42 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int character, size_t size)
{
	unsigned char	*m;

	m = (unsigned char *)mem;
	while (size--)
	{
		if (*m == (unsigned char)character)
			return (m);
		m++;
	}
	return (NULL);
}
