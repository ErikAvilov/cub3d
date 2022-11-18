/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_strrchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:10:59 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/13 07:49:10 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_strrchr(const char *s, int c, int index)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i - index]);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i - index]);
	return ((char *) NULL);
}
