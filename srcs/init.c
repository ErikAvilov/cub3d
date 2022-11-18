/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:52:42 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 14:12:30 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	init_bresenham(t_mlx_data *mlx_data, int x, int y)
{
	mlx_data->bres_val.x1 = mlx_data->res.center_x;
	mlx_data->bres_val.y1 = mlx_data->res.center_y;
	mlx_data->bres_val.x2 = x;
	mlx_data->bres_val.y2 = y;
	mlx_data->bres_val.dx = x - mlx_data->bres_val.x1;
	mlx_data->bres_val.dy = y - mlx_data->bres_val.y1;
	mlx_data->bres_val.err = mlx_data->bres_val.dx - mlx_data->bres_val.dy;
	mlx_data->bres_val.e2 = mlx_data->bres_val.err << 1;
}

void	ft_bresenham(t_mlx_data *mlx_data, int x, int y, int color)
{
	init_bresenham(mlx_data, x, y);
	printf("start is x: %d y: %d\n", mlx_data->bres_val.x1, mlx_data->bres_val.y1);
	printf("destination is x: %d y: %d\n", mlx_data->bres_val.x2, mlx_data->bres_val.y2);
	printf("distance is x: %d y: %d\n", mlx_data->bres_val.dx, mlx_data->bres_val.dy);
	printf("error value and hypothenuse is err: %d e2: %d\n", mlx_data->bres_val.err, mlx_data->bres_val.e2);
	(void) color;
}
