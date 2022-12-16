/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:42:58 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/16 13:09:02 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

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
