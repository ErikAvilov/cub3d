/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/26 00:02:11 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	rotate_right(t_mlx_data *mlx_data)
{
	double	rot_speed;
	double	old_dir_x;

	rot_speed = 1.5f;
	old_dir_x = mlx_data->player.dir[0];
	mlx_data->player.dir[0] = mlx_data->player.dir[0] * cos(rot_speed) - mlx_data->player.dir[1] * sin(rot_speed);
	mlx_data->player.dir[1] = old_dir_x * sin(rot_speed) + mlx_data->player.dir[1] * cos(rot_speed);
	printf("player is now diring x: %f y: %f\n", mlx_data->player.dir[0], mlx_data->player.dir[1]);
}

int	loop(t_mlx_data *mlx_data)
{
	mlx_data->img.image = mlx_new_image(mlx_data->mlx, RES_X, RES_Y);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.image,
		&mlx_data->img.bits_per_pixel, &mlx_data->img.line_length,
			&mlx_data->img.endian);
	if (is_pressed(mlx_data->moves.key, LEFT_ARROW))
	{
		update_angle(mlx_data, 1);
	}
	if (is_pressed(mlx_data->moves.key, RIGHT_ARROW))
	{
		rotate_right(mlx_data);
	}
	if (is_pressed(mlx_data->moves.key, K_W))
	{
		mlx_data->player.pos[1]--;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->floor,
			mlx_data->player.pos[0] - 5, mlx_data->player.pos[1] - 6);
	//ft_bresenham(mlx_data, mlx_data->player.watch[0], mlx_data->player.watch[1], BLUE);
	//mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
	return (0);
}