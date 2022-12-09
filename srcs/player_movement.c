/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:13:45 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/09 12:55:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	move_front(t_mlx_data *mlx_data, float speed)
{
	if (is_pressed(mlx_data->moves.key, K_S) || blocked(mlx_data, K_W))
		return ;
	mlx_data->player.pos.x += cos(-mlx_data->angle) * speed;
	mlx_data->player.pos.y += sin(-mlx_data->angle) * speed;
}

void	move_behind(t_mlx_data *mlx_data, float speed)
{
	if (is_pressed(mlx_data->moves.key, K_W) || blocked(mlx_data, K_S))
		return ;
	mlx_data->player.pos.x -= cos(-mlx_data->angle) * speed;
	mlx_data->player.pos.y -= sin(-mlx_data->angle) * speed;
}

void	strafe_left(t_mlx_data *mlx_data, float speed)
{
	if (is_pressed(mlx_data->moves.key, K_D) || blocked(mlx_data, K_A))
		return ;
	mlx_data->player.pos.x += mlx_data->moves.newdir.x * speed;
	mlx_data->player.pos.y += mlx_data->moves.newdir.y * speed;
}

void	strafe_right(t_mlx_data *mlx_data, float speed)
{
	if (is_pressed(mlx_data->moves.key, K_A) || blocked(mlx_data, K_D))
		return ;
	mlx_data->player.pos.x -= mlx_data->moves.newdir.x * speed;
	mlx_data->player.pos.y -= mlx_data->moves.newdir.y * speed;
}

void	check_action(t_mlx_data *mlx_data)
{
	double	speed;

	speed = 3.0f;
	if (is_pressed(mlx_data->moves.key, K_W))
		move_front(mlx_data, speed);
	if (is_pressed(mlx_data->moves.key, K_S))
		move_behind(mlx_data, speed);
	if (is_pressed(mlx_data->moves.key, K_A))
		strafe_left(mlx_data, speed);
	if (is_pressed(mlx_data->moves.key, K_D))
		strafe_right(mlx_data, speed);
	if (is_pressed(mlx_data->moves.key, LEFT_ARROW))
		rotate_left(mlx_data);
	if (is_pressed(mlx_data->moves.key, RIGHT_ARROW))
		rotate_right(mlx_data);
}
