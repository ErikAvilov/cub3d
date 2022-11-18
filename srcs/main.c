/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:55:16 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 14:11:14 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	mouse_press(int button, int x, int y, t_mlx_data *mlx_data)
{
	printf("clic at x: %d y: %d\n", x, y);
	(void) button;
	if (button == LMB)
	 	bresenham(mlx_data, x, y, WHITE);
	// else if (button == RMB)
	// 	draw_square(mlx_data, x, y, RED);
	return (0);
}

void	draw_line(t_mlx_data *mlx_data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	err;
	int	e2;

	x1 = 430;
	y1 = 320;
	x2 = 719;
	y2 = 395;
	dx = x2 - x1; // 289
	dy = y2 - y1;
	err = dx - dy; // 214
	e2 = 2*err; // 428
	while (x1 <= x2)
	{
		e2 = 2*err;
		my_mlx_pixel_put(&mlx_data->img, x1, y1, BLUE);
		if (e2 > -(y2 - y1))
		{
			err -= dy;
			x1++;
		}
		else
		{
			err += (x2 - x1);
			y1++;
		}
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
}

int	main(void)
{
	t_mlx_data	mlx_data;

	window_init(&mlx_data);
	mlx_hook(mlx_data.win, 2, 0, key_press, &mlx_data);
	mlx_hook(mlx_data.win, 3, 0, key_release, &mlx_data);
	mlx_mouse_hook(mlx_data.win, mouse_press, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, mlx_close, &mlx_data);
	mlx_data.img.image = mlx_new_image(mlx_data.mlx, mlx_data.res.res[0], mlx_data.res.res[1]);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.image, &mlx_data.img.bits_per_pixel, &mlx_data.img.line_length, &mlx_data.img.endian);
	draw_median(&mlx_data);
	draw_line(&mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.floor,
			mlx_data.res.center_x - 5, mlx_data.res.center_y - 6);
	mlx_loop_hook(mlx_data.mlx, loop, &mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}
