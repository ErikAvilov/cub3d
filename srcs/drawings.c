/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:57 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/24 05:24:03 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	draw_line(t_mlx_data *mlx_data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	err;
	int	e2;

	x1 = 430;
	y1 = 320;
	x2 = 719;
	y2 = 395;
	dx = x2 - x1; // 289
	dy = y2 - y1;
	err = dx - dy; // 214
	e2 = 2*err; // 428
	while (x1 <= x2)
	{
		if (x1 >= x2)
			break ;
		e2 = 2*err;
		my_mlx_pixel_put(&mlx_data->img, x1, y1, BLUE);
		if (e2 > -(y2 - y1))
		{
			err -= dy;
			x1++;
		}
		else
		{
			err += dx;
			y1++;
		}
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
}

void	draw_median(t_mlx_data *mlx_data)
{
	int	x1;
	int	y1;
	int	x;
	int	y;

	x1 = mlx_data->res.center_x;
	y1 = mlx_data->res.center_y;
	x = 0;
	y = 0;
	while (y < RES_Y - 1)
	{
		my_mlx_pixel_put(&mlx_data->img, x1, y, RED);
		y++;
	}
	while (x < RES_X - 1)
	{
		my_mlx_pixel_put(&mlx_data->img, x, y1, RED);
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
}

void	draw_square(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	i1;
	int	i2;
	
	i1 = 0;
	i2 = 0;
	while (i2 < 60)
	{
		while (i1 < 60)
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
			x1 += 60;
			x++;
		}
		x = 0;
		y++;
		y1 += 59;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
}