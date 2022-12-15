/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:57 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/15 13:17:39 by eavilov          ###   ########.fr       */
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

unsigned long	hexa_to_color_sky(t_mlx_data *mlx_data)
{
	int			color;
	t_color_rgb	rgb;

	rgb.r = 47;
	rgb.g = 118;
	rgb.b = 240;
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}

unsigned long	hexa_to_color_floor(t_mlx_data *mlx_data)
{
	int			color;
	t_color_rgb	rgb;

	rgb.r = 146;
	rgb.g = 29;
	rgb.b = 45;
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}

void	floor_ceiling(t_mlx_data *mlx_data)
{
	int				x;
	int				y;
	unsigned long	sky;
	unsigned long	floor;
	
	sky = hexa_to_color_sky(mlx_data);
	floor = hexa_to_color_floor(mlx_data);
	x = 0;
	y = 0;
	while (y < (RES_Y / 2))
	{
		while (x < RES_X)
		{
			my_mlx_pixel_put(&mlx_data->img, x, y, sky);
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	while (y < RES_Y)
	{
		while (x < RES_X)
		{
			my_mlx_pixel_put(&mlx_data->img, x, y, floor);
			x++;
		}
		x = 0;
		y++;
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
	// while (y < mlx_data->tableau.height)
	// {
	// 	while (x < mlx_data->tableau.width)
	// 	{
	// 		if (mlx_data->tableau.tab[y][x] == 1)
	// 			draw_square(mlx_data, x1, y1, color);
	// 		else
	// 			draw_square(mlx_data, x1, y1, BLACK);
	// 		x1 += 40;
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// 	y1 += 39;
	// }
	while (mlx_data->map[x])
	{
		while (mlx_data->map[x][y])
		{
			if (mlx_data->map[x][y] == '1')
				draw_square(mlx_data, x1, y1, color);
			else
				draw_square(mlx_data, x1, y1, BLACK);
			x1 += 40;
			y++;
		}
		y = 0;
		x++;
		y1 += 39;
	}
}
