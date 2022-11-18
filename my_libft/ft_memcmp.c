/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:03:13 by eavilov           #+#    #+#             */
/*   Updated: 2021/12/16 09:24:28 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	p1 = ptr1;
	p2 = ptr2;
	if (p1 == NULL && p2 == NULL)
		return (0);
	if (size == 0)
		return (0);
	size -= 1;
	while (size--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
