/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:14:34 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 11:32:33 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	collided(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y / 40][x / 40] == '1')
		return (1);
	return (0);
}

void	iter_x(t_mlx_data *mlx_data)
{
	mlx_data->dda_val.side.x += mlx_data->dda_val.delta.x;
	mlx_data->dda_val.map.x += mlx_data->dda_val.step.x;
	mlx_data->dda_val.map.side_hit.x = mlx_data->dda_val.step.x;
	mlx_data->dda_val.map.side_hit.y = 0;
	mlx_data->dda_val.map.perp_len = ((mlx_data->dda_val.side.x
				- mlx_data->dda_val.delta.x) * 2500);
}

void	iter_y(t_mlx_data *mlx_data)
{
	mlx_data->dda_val.side.y += mlx_data->dda_val.delta.y;
	mlx_data->dda_val.map.y += mlx_data->dda_val.step.y;
	mlx_data->dda_val.map.side_hit.y = mlx_data->dda_val.step.y;
	mlx_data->dda_val.map.side_hit.x = 0;
	mlx_data->dda_val.map.perp_len = ((mlx_data->dda_val.side.y
				- mlx_data->dda_val.delta.y) * 2500);
}

t_vector_2f	dda(t_mlx_data *mlx_data, int x, int y, int first)
{
	int			i;
	t_vector_2f	empty;

	dda_init(mlx_data, x, y);
	i = 0;
	empty.x = -1;
	empty.y = -1;
	while (1)
	{
		if (mlx_data->dda_val.side.x < mlx_data->dda_val.side.y)
			iter_x(mlx_data);
		else
			iter_y(mlx_data);
		if (collided(mlx_data, mlx_data->dda_val.map.x,
				mlx_data->dda_val.map.y))
			return (mlx_data->dda_val.map);
		if (i >= 3000 && first == 1)
			return (empty);
		i++;
	}
	return (mlx_data->dda_val.map);
}
