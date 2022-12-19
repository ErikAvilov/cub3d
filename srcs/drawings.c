/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:57 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/19 18:19:48 by eavilov          ###   ########.fr       */
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

void	display_zone(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while (i < RES_Y)
	{
		my_mlx_pixel_put(&mlx_data->img, 740, i, PINK);
		my_mlx_pixel_put(&mlx_data->img, 540, i, PINK);
		i++;
	}
}

void	floor_ceiling(t_mlx_data *mlx_data)
{
	int				x;
	int				y;
	unsigned long	sky;
	unsigned long	floor;

	sky = val_to_rgb(mlx_data, 168, 107, 14);
	floor = val_to_rgb(mlx_data, 50, 29, 45);
	x = -1;
	y = 0;
	while (y < (RES_Y / 2))
	{
		while (++x < RES_X)
			my_mlx_pixel_put(&mlx_data->img, x, y, sky);
		x = 0;
		y++;
	}
	x = -1;
	while (y < RES_Y)
	{
		while (++x < RES_X)
			my_mlx_pixel_put(&mlx_data->img, x, y, floor);
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
