/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:52:42 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/25 23:18:21 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

float	ft_abs(float nbr)
{
	if (nbr < 0.0f)
		return (-nbr);
	else
		return (nbr);
}

int	collided(t_mlx_data *mlx_data, int x, int y)
{
	t_vector_2d		cell;
	
	cell.x = x / 60;
	cell.y = y / 60;
	if (mlx_data->tableau.tab[cell.y][cell.x] == 1)
		return (1);
	return (0);
}

t_vector_2d	dda(t_mlx_data *mlx_data, int x, int y)
{
	t_vector_2d	origin = {RES_X * 0.5, RES_Y * 0.5};
	
	t_vector_2d	map = origin;
	t_vector_f	dir = {x - (RES_X * 0.5), y - (RES_Y * 0.5)};
	
	
	t_vector_f	side;
	t_vector_f	delta;
	static int	i = 0;

	if (dir.x == 0.0f)
		delta.x = 1e30;
	else
		delta.x = ft_abs(1.0f / dir.x);
	if (dir.y == 0.0f)
		delta.y = 1e30;
	else
		delta.y = ft_abs(1.0f / dir.y);
	t_vector_2d	step;
	if (dir.x < 0)
	{
		step.x = -1;
		side.x = (origin.x - map.x) * delta.x;
	}
	else
	{
		step.x = 1;
		side.x = ((map.x + 1.0f) - origin.x) * delta.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		side.y = (origin.y - map.y) * delta.y;
	}
	else
	{
		step.y = 1;
		side.y = ((map.y + 1.0f) - origin.y) * delta.y;
	}
	while (1)
	{
		if (side.x < side.y)
		{
			side.x += delta.x;
			map.x += step.x;
		}
		else
		{
			side.y += delta.y;
			map.y += step.y;
		}
		if (collided(mlx_data, map.x, map.y))
		{
			//printf("side.x: %f side.y: %f\n", side.x, side.y);
			//printf("COLLISION #%d DETECTED AT X: %d Y: %d\n", i++, map.x, map.y);
			return (map);
		}
	}
	return (origin);
}

void	init_angle(t_mlx_data *mlx_data)
{
	double	ray1;
	double	ray2;
	int opposite = 0;
	int	i = 0;
	double	adder;

	opposite = tan(45 / (180.0f / PI)) * 350;
	ray1 = mlx_data->bres_val.angle + PI / 2;
	ray2 = mlx_data->bres_val.angle - PI / 2; 	
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy < 0)
		mlx_data->bres_val.angle = atan((double)-mlx_data->bres_val.dy / (double)mlx_data->bres_val.dx);
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy < 0)
		mlx_data->bres_val.angle = atan(((double)mlx_data->bres_val.dx / (double)mlx_data->bres_val.dy)) + PI / 2.0f;
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy > 0)
		mlx_data->bres_val.angle = atan(((double)-mlx_data->bres_val.dy / (double)mlx_data->bres_val.dx)) + 3.14f;
	else
		mlx_data->bres_val.angle = atan(((double)mlx_data->bres_val.dx / (double)mlx_data->bres_val.dy)) + 3.14 + 1.57f;
	mlx_data->vector[0].x = cos(-mlx_data->bres_val.angle) * opposite + RES_X / 2;
	mlx_data->vector[0].y = sin(-mlx_data->bres_val.angle) * opposite + RES_Y / 2;
	while (i < 400)
	{
		if (!(i % 2))
		{
			mlx_data->vector[i].x = cos(-ray1) * opposite * adder + mlx_data->vector[0].x;
			mlx_data->vector[i].y = sin(-ray1) * opposite * adder + mlx_data->vector[0].y;
			adder += 0.004;
		}
		else
		{
			mlx_data->vector[i].x = cos(-ray2) * opposite * adder + mlx_data->vector[0].x;
			mlx_data->vector[i].y = sin(-ray2) * opposite * adder + mlx_data->vector[0].y;
		}
		i++;
	}
}

void	init_bresenham(t_mlx_data *mlx_data, int x, int y)
{
	int	i;

	i = -1;
	mlx_data->bres_val.x1 = mlx_data->player.pos[0];
	mlx_data->bres_val.y1 = mlx_data->player.pos[1];
	mlx_data->bres_val.x2 = x;
	mlx_data->bres_val.y2 = y;
	mlx_data->bres_val.dx = x - mlx_data->bres_val.x1;
	mlx_data->bres_val.dy = y - mlx_data->bres_val.y1;
	mlx_data->bres_val.err = mlx_data->bres_val.dx - mlx_data->bres_val.dy;
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
