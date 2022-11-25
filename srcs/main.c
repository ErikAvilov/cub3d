/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:55:16 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/26 00:02:18 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(void)
{
	t_mlx_data	mlx_data;

	window_init(&mlx_data);
	mlx_hook(mlx_data.win, 2, 0, key_press, &mlx_data);
	mlx_hook(mlx_data.win, 3, 0, key_release, &mlx_data);
	mlx_hook(mlx_data.win, 4, 0, mouse_press, &mlx_data);
	mlx_hook(mlx_data.win, 5, 0, mouse_release, &mlx_data);
	mlx_hook(mlx_data.win, 6, 0, mouse_move, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, mlx_close, &mlx_data);
	mlx_data.img.image = mlx_new_image(mlx_data.mlx, RES_X, RES_Y);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.image, &mlx_data.img.bits_per_pixel, &mlx_data.img.line_length, &mlx_data.img.endian);
	//draw_damier(&mlx_data);
	//draw_median(&mlx_data);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.floor,
			mlx_data.res.center_x - 5, mlx_data.res.center_y - 6);
	mlx_loop_hook(mlx_data.mlx, loop, &mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}
