/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:42:58 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/26 00:02:34 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

double	find_angle(t_mlx_data *mlx_data)
{
	double	result;
	if (mlx_data->bres_val.dx >= 0 && mlx_data->bres_val.dy < 0)
		result = atan((double)-mlx_data->bres_val.dy / (double)mlx_data->bres_val.dx);
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy < 0)
		result = atan(((double)mlx_data->bres_val.dx / (double)mlx_data->bres_val.dy)) + PI / 2.0f;
	else if (mlx_data->bres_val.dx < 0 && mlx_data->bres_val.dy > 0)
		result = atan(((double)-mlx_data->bres_val.dy / (double)mlx_data->bres_val.dx)) + 3.14f;
	else
		result = atan(((double)mlx_data->bres_val.dx / (double)mlx_data->bres_val.dy)) + 3.14 + 1.57f;
	return (result);
}

void	update_angle(t_mlx_data *mlx_data, int direction)
{
	double	ray1;
	double	ray2;

	ray1 = mlx_data->bres_val.angle + PI / 2;
	ray2 = mlx_data->bres_val.angle - PI / 2; 	
	mlx_data->bres_val.angle = find_angle(mlx_data);
	// if (direction == 1)
	// {
	// 	mlx_data->player.watch[0] = cos(-ray1) * 2 + cos(-mlx_data->bres_val.angle) * 150 + RES_X / 2;
	// 	mlx_data->player.watch[1] = sin(-ray1) * 2 + sin(-mlx_data->bres_val.angle) * 150 + RES_Y / 2;
	// }
	// else if (direction == 2)
	// {
	// 	mlx_data->player.watch[0] = cos(-ray2) * 3.5f + cos(-mlx_data->bres_val.angle) * 150 + RES_X / 2;
	// 	mlx_data->player.watch[1] = sin(-ray2) * 3.5f + sin(-mlx_data->bres_val.angle) * 150 + RES_Y / 2;
	// }
}
