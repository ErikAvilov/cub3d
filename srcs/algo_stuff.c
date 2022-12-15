/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:11:20 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/15 12:50:52 by eavilov          ###   ########.fr       */
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

t_vector_2f	lerp(t_vector_2f start, t_vector_2f end, float i)
{
	t_vector_2f vect;
	float		dx;
	float		dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	vect.x = start.x + dx * i;
	vect.y = start.y + dy * i;
	return (vect);
}

void	rays_init(t_mlx_data *mlx_data)
{
	int			i;
	double		adder;
	t_vector_2f	limit;
	t_vector_2f test;
	int			dx;
	int			dy;
	float		increment = 1.0f / (1280 - 1.0f);
	int op = tan(FOV / (180.0 / PI)) * 1000;

	i = -1;
	dx = 0;
	dy = 0;
	limit = vision_limit(mlx_data->player.pos, mlx_data->angle, 2560);
	t_vector_2f	vect[2] = {
		vision_limit(limit, mlx_data->angle + PI / 2, op),
		vision_limit(limit, mlx_data->angle - PI / 2, op)
	};
	while (++i < mlx_data->rays.amount)
	{
		mlx_data->vector[i] = lerp(vect[0], vect[1], increment * i);
		mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x,
	 			mlx_data->vector[i].y);
		dx = mlx_data->vector[i].x - mlx_data->player.pos.x;
	 	dy = mlx_data->vector[i].y - mlx_data->player.pos.y;
 		mlx_data->vector[i].length = sqrt(dx * dx + dy * dy);
	}
//	printf("perp: %f\n", mlx_data->vector[500].perp_len);
//	printf("length: %f\n", mlx_data->vector[500].length);
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
