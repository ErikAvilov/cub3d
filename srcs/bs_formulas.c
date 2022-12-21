/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:28:35 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/21 14:00:57 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_vector_2f	vision_limit(t_vector_2f origin, double angle, int limit)
{
	t_vector_2f	result;

	result.x = cos(-angle) * limit + origin.x;
	result.y = sin(-angle) * limit + origin.y;
	return (result);
}

t_vector_2f	lerp(t_vector_2f start, t_vector_2f end, float i)
{
	t_vector_2f	vect;
	float		dx;
	float		dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	vect.x = start.x + dx * i;
	vect.y = start.y + dy * i;
	return (vect);
}

unsigned long	val_to_rgb(t_mlx_data *mlx_data, int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	texture_pixel_color(t_textures *text, int x, int y)
{
	return (*(int *)(text->text_adr + (y * text->line_length) + (x * text->bits_per_pixel / 8)));
}
