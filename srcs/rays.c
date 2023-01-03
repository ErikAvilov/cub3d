/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:42:58 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/22 16:15:36 by eavilov          ###   ########.fr       */
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

double	find_angle(t_mlx_data *mlx_data, int x, int y)
{
	double	result;

	init_bresenham(mlx_data, x, y);
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy < 0)
		result = atan((double)-mlx_data->bres_val.dy
				/ (double)mlx_data->bres_val.dx);
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy < 0)
		result = atan(((double)mlx_data->bres_val.dx
					/ (double)mlx_data->bres_val.dy)) + PI * 0.5f;
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy > 0)
		result = atan(((double)-mlx_data->bres_val.dy
					/ (double)mlx_data->bres_val.dx)) + 3.14f;
	else
		result = atan(((double)mlx_data->bres_val.dx
					/ (double)mlx_data->bres_val.dy)) + 3.14 + 1.57f;
	return (result);
}

float	get_angle(t_mlx_data *mlx_data, t_vector_2f player, t_vector_2f dest)
{
	double	dx;
	double	dy;

	(void) mlx_data;
	dx = (double)(dest.x - player.x);
	dy = (double)(dest.y - player.y);
	if (dx >= 0 && dy < 0)
		return (atan(-dy / dx));
	else if (dx < 0 && dy < 0)
		return (atan(dx / dy) + 3.14f / 2.0f);
	else if (dx < 0 && dy > 0)
		return (atan(-dy / dx) + 3.14f);
	else
		return (atan(dx / dy) + 3.14 + 1.57f);
}
