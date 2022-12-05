/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:31:49 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/05 09:47:20 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	bottom_right(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	e2;

	// printf("bot right\n");
	e2 = 2 * mlx_data->bres_val.err;
	while (mlx_data->bres_val.x1 <= x && mlx_data->bres_val.y1 <= y)
	{
		if (mlx_data->bres_val.x1 == x
			&& mlx_data->bres_val.y1 == y)
			break ;
		e2 = 2 * mlx_data->bres_val.err;
		my_mlx_pixel_put(&mlx_data->img, mlx_data->bres_val.x1,
			mlx_data->bres_val.y1, color);
		if (e2 > -mlx_data->bres_val.dy)
		{
			mlx_data->bres_val.err -= mlx_data->bres_val.dy;
			mlx_data->bres_val.x1++;
		}
		else
		{
			mlx_data->bres_val.err += mlx_data->bres_val.dx;
			mlx_data->bres_val.y1++;
		}
	}
}

void	bottom_left(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	e2;

	// printf("bot left\n");
	e2 = 2 * mlx_data->bres_val.err;
	while (mlx_data->bres_val.x1 >= x)
	{
		if (mlx_data->bres_val.x1 == x
			&& mlx_data->bres_val.y1 == y)
			break ;
		e2 = 2 * mlx_data->bres_val.err;
		my_mlx_pixel_put(&mlx_data->img, mlx_data->bres_val.x1,
			mlx_data->bres_val.y1, color);
		if (e2 > -mlx_data->bres_val.dy)
		{
			mlx_data->bres_val.err -= mlx_data->bres_val.dy;
			mlx_data->bres_val.x1--;
		}
		else
		{
			mlx_data->bres_val.err -= mlx_data->bres_val.dx;
			mlx_data->bres_val.y1++;
		}
	}
}

void	top_left(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	e2;

	// printf("top left\n");
	e2 = 2 * mlx_data->bres_val.err;
	while (mlx_data->bres_val.x1 >= x && mlx_data->bres_val.y1 >= y)
	{
		if (mlx_data->bres_val.x1 == x
			&& mlx_data->bres_val.y1 == y)
			break ;
		e2 = 2 * mlx_data->bres_val.err;
		my_mlx_pixel_put(&mlx_data->img, mlx_data->bres_val.x1,
			mlx_data->bres_val.y1, color);
		if (e2 > -mlx_data->bres_val.dy)
		{
			mlx_data->bres_val.err += mlx_data->bres_val.dy;
			mlx_data->bres_val.x1--;
		}
		else
		{
			mlx_data->bres_val.err -= mlx_data->bres_val.dx;
			mlx_data->bres_val.y1--;
		}
	}
}

void	top_right(t_mlx_data *mlx_data, int x, int y, int color)
{
	int	e2;

	// printf("top right\n");
	e2 = 2 * mlx_data->bres_val.err;
	while (mlx_data->bres_val.y1 >= y && mlx_data->bres_val.x1 <= x)
	{
		if (mlx_data->bres_val.x1 == x
			&& mlx_data->bres_val.y1 == y)
			break ;
		e2 = 2 * mlx_data->bres_val.err;
		my_mlx_pixel_put(&mlx_data->img, mlx_data->bres_val.x1,
			mlx_data->bres_val.y1, color);
		if (e2 > -mlx_data->bres_val.dy)
		{
			mlx_data->bres_val.err += mlx_data->bres_val.dy;
			mlx_data->bres_val.x1++;
		}
		else
		{
			mlx_data->bres_val.err += mlx_data->bres_val.dx;
			mlx_data->bres_val.y1--;
		}
	}
}
