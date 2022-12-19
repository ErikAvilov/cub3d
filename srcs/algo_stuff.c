/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:11:20 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/19 18:09:17 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	vectors_init(t_mlx_data *mlx_data, t_vector_2f *gap)
{
	int		dx;
	int		dy;
	int		i;
	float	inc;
	
	i = -1;
	dx = 0;
	dy = 0;
	inc = 1.0f / (mlx_data->rays.amount - 1.0f);
	while (++i < mlx_data->rays.amount)
	{
		mlx_data->vector[i] = lerp(gap[0], gap[1], inc * i);
		mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x,
	 			mlx_data->vector[i].y);
		mlx_data->vector[i].angle = get_angle(mlx_data, mlx_data->player.pos,
				mlx_data->vector[i]);
		dx = mlx_data->vector[i].x - mlx_data->player.pos.x;
	 	dy = mlx_data->vector[i].y - mlx_data->player.pos.y;
 		mlx_data->vector[i].length = sqrt(dx * dx + dy * dy);
	}
}

void	rays_init(t_mlx_data *mlx_data)
{
	int			i;
	t_vector_2f	limit;
	t_vector_2f	gap[2];
	int 		op;

	i = -1;
	op = tan(FOV / (180.0 / PI)) * 1000;
	limit = vision_limit(mlx_data->player.pos, mlx_data->angle, 2560);
	gap[0] = vision_limit(limit, mlx_data->angle + PI / 2, op);
	gap[1] = vision_limit(limit, mlx_data->angle - PI / 2, op);
	vectors_init(mlx_data, gap);
}

void	algo_init(t_mlx_data *mlx_data)
{
	rays_init(mlx_data);
	mlx_data->img.image = mlx_new_image(mlx_data->mlx, RES_X, RES_Y);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.image,
			&mlx_data->img.bits_per_pixel, &mlx_data->img.line_length,
			&mlx_data->img.endian);
}
