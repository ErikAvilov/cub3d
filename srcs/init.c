/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:52:42 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/05 12:30:29 by eavilov          ###   ########.fr       */
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
	
	cell.x = x / 40;
	cell.y = y / 40;
	if (mlx_data->tableau.tab[cell.y][cell.x] == 1)
		return (1);
	return (0);
}

t_vector_2d	dda(t_mlx_data *mlx_data, int x, int y)
{
	t_vector_2d	origin = {mlx_data->player.pos[0], mlx_data->player.pos[1]};
	
	t_vector_2d	map = origin;
	t_vector_f	dir = {x - origin.x, y - origin.y};
	double		angle = find_angle(mlx_data, x, y);
	t_vector_2d	limit = vision_limit(origin, angle, 300);

	t_vector_f	side;
	t_vector_f	delta;
	int	i = 0;
	static int bite = 0;

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
		if (mlx_data->bres_val.dx <= 0 && mlx_data->bres_val.dy <= 0  && (limit.y >= 39 && limit.y <= 561) && (limit.x >= 39 && limit.x <= 761))
		{
			if (map.x <= limit.x && map.y >= limit.y)
			{
				// printf("1 dx: %d dy: %d\n", mlx_data->bres_val.dx, mlx_data->bres_val.dy);
				// printf("1 limit.x: %d limit.y: %d\n", limit.x, limit.y);
				// printf("1 map.x: %d map.y: %d\n\n", map.x, map.y);
				return (limit);
			}
		}
		if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy <= 0  && (limit.y >= 39 && limit.y <= 561) && (limit.x >= 39 && limit.x <= 761))
		{
			if (map.x <= limit.x && map.y <= limit.y)
			{
				// printf("1 dx: %d dy: %d\n", mlx_data->bres_val.dx, mlx_data->bres_val.dy);
				// printf("1 limit.x: %d limit.y: %d\n", limit.x, limit.y);
				// printf("1 map.x: %d map.y: %d\n\n", map.x, map.y);
				return (limit);
			}
		}
		if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy >= 0  && (limit.y >= 39 && limit.y <= 561) && (limit.x >= 39 && limit.x <= 761))
		{
			if (map.x >= limit.x && map.y <= limit.y)
			{
				// printf("1 dx: %d dy: %d\n", mlx_data->bres_val.dx, mlx_data->bres_val.dy);
				// printf("1 limit.x: %d limit.y: %d\n", limit.x, limit.y);
				// printf("1 map.x: %d map.y: %d\n\n", map.x, map.y);
				return (limit);
			}
		}
		if (map.x >= limit.x && map.y >= limit.y && (limit.y >= 39 && limit.x >= 39))
		{
			// printf("3 dx: %d dy: %d\n", mlx_data->bres_val.dx, mlx_data->bres_val.dy);
			// printf("3 limit.x: %d limit.y: %d\n", limit.x, limit.y);
			// printf("3 map.x: %d map.y: %d\n\n", map.x, map.y);
			return (limit);
		}
		if (collided(mlx_data, map.x, map.y))
		{
			// printf("COLLISION\n");
			// printf("%d dx: %d dy: %d\n", bite, mlx_data->bres_val.dx, mlx_data->bres_val.dy);
			// printf("%d map.x: %d map.y: %d\n", bite, map.x, map.y);
			// printf("%d limit.x: %d limit.y: %d\n\n", bite, limit.x, limit.y);
			bite++;
			return (map);
		}
		i++;
	}
	return (map);
}

void	init_angle(t_mlx_data *mlx_data)
{
	double	ray1;
	double	ray2;
	int opposite = 0;
	int	i = 0;
	double	adder;

	opposite = tan(45 / (180.0f / PI)) * 800;
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
	mlx_data->vector[0].x = cos(-mlx_data->bres_val.angle) * opposite + mlx_data->player.pos[0];
	mlx_data->vector[0].y = sin(-mlx_data->bres_val.angle) * opposite + mlx_data->player.pos[1];
	while (i < 800)
	{
		if (!(i % 2))
		{
			mlx_data->vector[i].x = cos(-ray1) * opposite * adder + mlx_data->vector[0].x;
			mlx_data->vector[i].y = sin(-ray1) * opposite * adder + mlx_data->vector[0].y;
			adder += 0.002;
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
	mlx_data->bres_val.err = abs(mlx_data->bres_val.dx) - abs(mlx_data->bres_val.dy);
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
