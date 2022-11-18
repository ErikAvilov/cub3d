/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:45:08 by eavilov           #+#    #+#             */
/*   Updated: 2021/11/12 17:53:29 by eavilov          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (character >= 'A' && character <= 'Z'
		| character >= 'a' && character <= 'z')
		return (1);
	else if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}
