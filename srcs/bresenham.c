/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:52:42 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/07 08:18:35 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	init_bresenham(t_mlx_data *mlx_data, int x, int y)
{
	int	i;

	i = -1;
	mlx_data->bres_val.x1 = mlx_data->player.pos.x;
	mlx_data->bres_val.y1 = mlx_data->player.pos.y;
	mlx_data->bres_val.dx = x - mlx_data->bres_val.x1;
	mlx_data->bres_val.dy = y - mlx_data->bres_val.y1;
	mlx_data->bres_val.err = abs(mlx_data->bres_val.dx)
		- abs(mlx_data->bres_val.dy);
}

void	ft_bresenham(t_mlx_data *mlx_data, int x, int y, int color)
{
	init_bresenham(mlx_data, x, y);
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy < 0)
		top_right(mlx_data, x, y, color);
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy <= 0)
		top_left(mlx_data, x, y, color);
	else if (mlx_data->bres_val.dx <= 0 && mlx_data->bres_val.dy >= 0)
		bottom_left(mlx_data, x, y, color);
	else if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy >= 0)
		bottom_right(mlx_data, x, y, color);
}
