/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:57 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/07 12:51:26 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	draw_square(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (i2 < 40)
	{
		while (i1 < 40)
		{
			my_mlx_pixel_put(&mlx_data->img, x + i1, y + i2, color);
			i1++;
		}
		i1 = 0;
		i2++;
	}
}

void	draw_damier(t_mlx_data *mlx_data, int color)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	while (y < mlx_data->tableau.height)
	{
		while (x < mlx_data->tableau.width)
		{
			if (mlx_data->tableau.tab[y][x] == 1)
				draw_square(mlx_data, x1, y1, color);
			else
				draw_square(mlx_data, x1, y1, BLACK);
			x1 += 40;
			x++;
		}
		x = 0;
		y++;
		y1 += 39;
	}
}
