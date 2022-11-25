/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:11:01 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/25 22:42:49 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	mouse_press(int button, int x, int y, t_mlx_data *mlx_data)
{
	if (button == LMB)
	{
		mlx_data->tableau.tab[y / 60][x / 60] = 0;
		draw_damier(mlx_data, WHITE);
	}
	else if (button == RMB)
	{
		mlx_data->tableau.tab[y / 60][x / 60] = 1;
		draw_damier(mlx_data, WHITE);
	}
	else if (button == 3)
		printf("clicked on x: %d y: %d\n", x, y);
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx_data *mlx_data)
{
	return (0);
}

int	mouse_move(int x, int y, t_mlx_data *mlx_data)
{
	mlx_data->img.image = mlx_new_image(mlx_data->mlx, RES_X, RES_Y);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.image, &mlx_data->img.bits_per_pixel, &mlx_data->img.line_length, &mlx_data->img.endian);
	int i = -1;
	draw_damier(mlx_data, WHITE);
	ft_bresenham(mlx_data, x, y, YELLOW);
	init_angle(mlx_data);
	while (++i < 400)
	{
		mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x, mlx_data->vector[i].y);
	 	ft_bresenham(mlx_data, mlx_data->vector[i].x, mlx_data->vector[i].y, RED);
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
	return (0);
}
