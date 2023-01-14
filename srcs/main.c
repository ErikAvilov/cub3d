/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:55:16 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/14 17:10:31 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int ac, char **av)
{
	t_mlx_data	mlx_data;

	window_init(&mlx_data, ac, av);
	mlx_hook(mlx_data.win, 2, 0, key_press, &mlx_data);
	mlx_hook(mlx_data.win, 3, 0, key_release, &mlx_data);
	mlx_hook(mlx_data.win, 6, 0, mouse_move, &mlx_data);
	mlx_hook(mlx_data.win, 17, 0, mlx_close, &mlx_data);
	mlx_data.img.image = mlx_new_image(mlx_data.mlx, RES_X, RES_Y);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.image,
			&mlx_data.img.bits_per_pixel, &mlx_data.img.line_length,
			&mlx_data.img.endian);
	mlx_loop_hook(mlx_data.mlx, loop, &mlx_data);
	mlx_loop(mlx_data.mlx);
	return (0);
}
