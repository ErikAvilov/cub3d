/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:11:52 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/08 08:46:55 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	dda_init(t_mlx_data *mlx_data, int x, int y)
{
	double		angle;

	angle = find_angle(mlx_data, x, y);
	mlx_data->dda_val.origin.x = mlx_data->player.pos.x;
	mlx_data->dda_val.origin.y = mlx_data->player.pos.y;
	mlx_data->dda_val.limit = vision_limit(mlx_data->dda_val.origin,
			angle, 300);
	mlx_data->dda_val.map = mlx_data->dda_val.origin;
	mlx_data->dda_val.dir.x = x - mlx_data->dda_val.origin.x;
	mlx_data->dda_val.dir.y = y - mlx_data->dda_val.origin.y;
	dda_init2(mlx_data);
}

void	dda_init2(t_mlx_data *mlx_data)
{
	if (mlx_data->dda_val.dir.x == 0.0f)
		mlx_data->dda_val.delta.x = 1e30;
	else
		mlx_data->dda_val.delta.x = ft_abs(1.0f / mlx_data->dda_val.dir.x);
	if (mlx_data->dda_val.dir.y == 0.0f)
		mlx_data->dda_val.delta.y = 1e30;
	else
		mlx_data->dda_val.delta.y = ft_abs(1.0f / mlx_data->dda_val.dir.y);
	dda_init3(mlx_data);
}

void	dda_init3(t_mlx_data *mlx_data)
{
	if (mlx_data->dda_val.dir.x < 0)
	{
		mlx_data->dda_val.step.x = -1;
		mlx_data->dda_val.side.x = (mlx_data->dda_val.origin.x
				- mlx_data->dda_val.map.x) * mlx_data->dda_val.delta.x;
	}
	else
	{
		mlx_data->dda_val.step.x = 1;
		mlx_data->dda_val.side.x = ((mlx_data->dda_val.map.x + 1.0f)
				- mlx_data->dda_val.origin.x) * mlx_data->dda_val.delta.x;
	}
	if (mlx_data->dda_val.dir.y < 0)
	{
		mlx_data->dda_val.step.y = -1;
		mlx_data->dda_val.side.y = (mlx_data->dda_val.origin.y
				- mlx_data->dda_val.map.y) * mlx_data->dda_val.delta.y;
	}
	else
	{
		mlx_data->dda_val.step.y = 1;
		mlx_data->dda_val.side.y = ((mlx_data->dda_val.map.y + 1.0f)
				- mlx_data->dda_val.origin.y) * mlx_data->dda_val.delta.y;
	}
}

int	bunch_of_ifs(t_mlx_data *mlx_data, t_vector_2f limit, t_vector_2f map)
{
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy >= 0
		&& (limit.y >= 39 && limit.y <= 681)
		&& (limit.x >= 39 && limit.x <= 1241))
	{
		if (map.x >= limit.x && map.y + 1 >= limit.y)
			return (1);
	}
	if (mlx_data->bres_val.dx <= 0 && mlx_data->bres_val.dy >= 0
		&& (limit.y >= 39 && limit.y <= 681)
		&& (limit.x >= 39 && limit.x <= 1241))
	{
		if (map.x <= limit.x + 1 && map.y >= limit.y)
			return (1);
	}
	return (0);
}

int	view_limit(t_mlx_data *mlx_data, t_vector_2f limit, t_vector_2f map)
{
	if (mlx_data->bres_val.dx <= 0 && mlx_data->bres_val.dy <= 0
		&& (limit.y >= 39 && limit.y <= 681)
		&& (limit.x >= 39 && limit.x <= 1241))
	{
		if (map.x <= limit.x && map.y <= limit.y)
			return (1);
	}
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy <= 0
		&& (limit.y >= 39 && limit.y <= 681)
		&& (limit.x >= 39 && limit.x <= 1241))
	{
		if (map.x >= limit.x && map.y <= limit.y)
			return (1);
	}
	if (bunch_of_ifs(mlx_data, mlx_data->dda_val.limit, mlx_data->dda_val.map))
		return (1);
	return (0);
}
