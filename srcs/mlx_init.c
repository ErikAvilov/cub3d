/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:48:15 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 14:11:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	value_init(t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	mlx_data->moves.fingers = 10;
	while (++i < mlx_data->moves.fingers)
		mlx_data->moves.key[i] = -1;
	mlx_data->img.bits_per_pixel = 0;
	mlx_data->img.line_length = 0;
	mlx_data->img.endian = 0;
	mlx_data->res.res[0] = RES_X;
	mlx_data->res.res[1] = RES_Y;
	mlx_data->res.center_x = RES_X >> 1;
	mlx_data->res.center_y = RES_Y >> 1;
	mlx_data->coords.x = 0;
	mlx_data->coords.y = 0;
}

void	window_init(t_mlx_data *mlx_data)
{
	int	dimension[2];

	value_init(&*mlx_data);
	dimension[0] = 64;
	dimension[1] = 64;
	mlx_data->mlx = mlx_init();
	mlx_data->floor = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/dot.xpm", &dimension[0], &dimension[1]);
	mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->res.res[0],
			mlx_data->res.res[1], "cub");
	mlx_do_key_autorepeatoff(mlx_data->mlx);
}
