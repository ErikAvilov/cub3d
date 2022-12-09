/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:11:20 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/09 13:22:11 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_vector_2f	vision_limit(t_vector_2f origin, double angle, int limit)
{
	t_vector_2f	result;

	result.x = cos(-angle) * limit + origin.x;
	result.y = sin(-angle) * limit + origin.y;
	return (result);
}

void	rays_init(t_mlx_data *mlx_data)
{
	int			i;
	double		adder;
	t_vector_2f	limit;
	int			dx;
	int			dy;

	i = -1;
	dx = 0;
	dy = 0;
	//limit = vision_limit(mlx_data->player.pos, mlx_data->angle, 1000);
	limit = vision_limit(mlx_data->player.pos, mlx_data->angle, 1000);
	// while (++i < mlx_data->rays.amount)
	// {
	// 	if (!(i % 2))
	// 	{
	// 		mlx_data->vector[i] = vision_limit(limit,
	// 				mlx_data->angle + PI2, mlx_data->rays.opposite * adder);
	// 		adder += mlx_data->rays.gap;
	// 	}
	// 	else
	// 		mlx_data->vector[i] = vision_limit(limit,
	// 				mlx_data->angle - PI2, mlx_data->rays.opposite * adder);
	// 	mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x,
	// 			mlx_data->vector[i].y);
	// 	dx = mlx_data->vector[i].x - mlx_data->player.pos.x;
	// 	dy = mlx_data->vector[i].y - mlx_data->player.pos.y;
	// 	mlx_data->vector[i].length = sqrt(dx * dx + dy * dy);
	// }
	while (++i < mlx_data->rays.amount)
	{
		mlx_data->vector[i] = vision_limit(limit,
				mlx_data->angle + PI2, mlx_data->rays.opposite * adder);
		adder += mlx_data->rays.gap;
		mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x,
				mlx_data->vector[i].y);
		dx = mlx_data->vector[i].x - mlx_data->player.pos.x;
		dy = mlx_data->vector[i].y - mlx_data->player.pos.y;
		mlx_data->vector[i].length = sqrt(dx * dx + dy * dy);
	}
	
}

void	algo_init(t_mlx_data *mlx_data)
{
	int		i;

	i = 0;
	rays_init(mlx_data);
	mlx_data->img.image = mlx_new_image(mlx_data->mlx, RES_X, RES_Y);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.image,
			&mlx_data->img.bits_per_pixel, &mlx_data->img.line_length,
			&mlx_data->img.endian);
}
