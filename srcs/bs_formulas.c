/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:28:35 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/16 12:44:13 by eavilov          ###   ########.fr       */
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

unsigned long	hexa_to_color_sky(t_mlx_data *mlx_data)
{
	t_color_rgb	rgb;

	rgb.r = 47;
	rgb.g = 118;
	rgb.b = 240;
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}

unsigned long	hexa_to_color_floor(t_mlx_data *mlx_data)
{
	t_color_rgb	rgb;

	rgb.r = 50;
	rgb.g = 29;
	rgb.b = 45;
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}
