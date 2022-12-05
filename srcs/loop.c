/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/05 12:25:36 by eavilov          ###   ########.fr       */
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
	//t_vector_2d vect;

	//vect.x = cos()
}

t_vector_2d	vision_limit(t_vector_2d origin, double angle, int limit)
{
	t_vector_2d	result;

	result.x = cos(-angle) * limit + origin.x;
	result.y = sin(-angle) * limit + origin.y;
	return (result);
}

int	loop(t_mlx_data *mlx_data)
{
	//mlx_data->img.image = mlx_new_image(mlx_data->mlx, RES_X, RES_Y);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.image,
		&mlx_data->img.bits_per_pixel, &mlx_data->img.line_length,
			&mlx_data->img.endian);
	int i = 0;
	double adder;
	//double	angle = find_angle(mlx_data, mlx_data->vector[0].x, mlx_data->vector[0].y);
	t_vector_2d pos = {mlx_data->player.pos[0], mlx_data->player.pos[1]};
	// init_angle(mlx_data);
	int opposite = tan(45 / (180.0f / PI)) * 400;
	double ray1 = mlx_data->angle + PI * 0.5f;
	double ray2 = mlx_data->angle - PI * 0.5f; 
	mlx_data->vector[0] = vision_limit(pos, mlx_data->angle, 400);
	int quantity = 800;
	float	space = 1 / (quantity * 0.5);
	while (++i < 800)
	{
		if (!(i%2))
		{
	 		mlx_data->vector[i] = vision_limit(mlx_data->vector[0], ray1, opposite * adder);
			adder += space;
		}
		else
			mlx_data->vector[i] = vision_limit(mlx_data->vector[0], ray2, opposite * adder);
	 	mlx_data->vector[i] = dda(mlx_data, mlx_data->vector[i].x, mlx_data->vector[i].y);
	}
	i = 0;
	draw_damier(mlx_data, WHITE);
	if (is_pressed(mlx_data->moves.key, LEFT_ARROW))
	{
		if (mlx_data->angle >= 6.28)
			mlx_data->angle = 0;
		mlx_data->angle += 0.04f;
	}
	if (is_pressed(mlx_data->moves.key, RIGHT_ARROW))
	{
		if (mlx_data->angle <= 0)
			mlx_data->angle = PI * 2.0f;
		mlx_data->angle -= 0.04f;
	}
	if (is_pressed(mlx_data->moves.key, K_W))
		mlx_data->player.pos[1] -= 4;
	else if (is_pressed(mlx_data->moves.key, K_S))
		mlx_data->player.pos[1] += 4;
	if (is_pressed(mlx_data->moves.key, K_A) && !is_pressed(mlx_data->moves.key, K_D))
		mlx_data->player.pos[0] -= 4;
	if (is_pressed(mlx_data->moves.key, K_D) && !is_pressed(mlx_data->moves.key, K_A))
		mlx_data->player.pos[0] += 4;
	// while (++i < quantity)
	// 	ft_bresenham(mlx_data, mlx_data->vector[i].x, mlx_data->vector[i].y, RED);
	while (++i < 800)
		ft_bresenham(mlx_data, mlx_data->vector[i].x, mlx_data->vector[i].y, RED);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
	// mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->floor,
	// 		mlx_data->player.pos[0] - 5, mlx_data->player.pos[1] - 6);
	return (0);
}