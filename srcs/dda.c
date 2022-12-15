/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:14:34 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/15 12:49:25 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	collided(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y / 40][x / 40] == '1')
		return (1);
	return (0);
}

t_vector_2f	dda(t_mlx_data *mlx_data, int x, int y)
{
	dda_init(mlx_data, x, y);
	while (1)
	{
		if (mlx_data->dda_val.side.x < mlx_data->dda_val.side.y)
		{
			mlx_data->dda_val.side.x += mlx_data->dda_val.delta.x;
			mlx_data->dda_val.map.x += mlx_data->dda_val.step.x;
			mlx_data->dda_val.map.side_hit.x = mlx_data->dda_val.step.x;
			mlx_data->dda_val.map.side_hit.y = 0;
			mlx_data->dda_val.map.perp_len = ((mlx_data->dda_val.side.x - mlx_data->dda_val.delta.x) * 40) * 60;
		}
		else
		{
			mlx_data->dda_val.side.y += mlx_data->dda_val.delta.y;
			mlx_data->dda_val.map.y += mlx_data->dda_val.step.y;
			mlx_data->dda_val.map.side_hit.y = mlx_data->dda_val.step.y;
			mlx_data->dda_val.map.side_hit.x = 0;
			mlx_data->dda_val.map.perp_len = ((mlx_data->dda_val.side.y - mlx_data->dda_val.delta.y) * 40) * 60;
		}
		if (collided(mlx_data, mlx_data->dda_val.map.x,
				mlx_data->dda_val.map.y))
			return (mlx_data->dda_val.map);
		// else if (view_limit(mlx_data, mlx_data->dda_val.limit,
		// 		mlx_data->dda_val.map))
		// 	return (mlx_data->dda_val.limit);
	}
	return (mlx_data->dda_val.map);
}
