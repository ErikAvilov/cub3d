/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:49:04 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/22 16:15:51 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_up(t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	cor1;
	int	cor2;

	x = mlx_data->player.pos.x;
	y = mlx_data->player.pos.y;
	if (cos(-mlx_data->angle) < 0)
		cor1 = -HEADSIZE;
	else
		cor1 = HEADSIZE;
	if (sin(-mlx_data->angle) < 0)
		cor2 = -HEADSIZE;
	else
		cor2 = HEADSIZE;
	if (mlx_data->map[(y + cor2) / 40][x / 40] == '1'
			|| mlx_data->map[y / 40][(x + cor1) / 40] == '1')
	{
		if (mlx_data->map[y / 40][(x + cor1) / 40] != '1')
			mlx_data->player.pos.x += cos(-mlx_data->angle) * 5;
		else if (mlx_data->map[(y + cor2) / 40][x / 40] != '1')
			mlx_data->player.pos.y += sin(-mlx_data->angle) * 5;
		return (1);
	}
	return (0);
}

int	check_down(t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	cor1;
	int	cor2;

	x = mlx_data->player.pos.x;
	y = mlx_data->player.pos.y;
	if (cos(-mlx_data->angle) < 0)
		cor1 = -HEADSIZE;
	else
		cor1 = HEADSIZE;
	if (sin(-mlx_data->angle) < 0)
		cor2 = -HEADSIZE;
	else
		cor2 = HEADSIZE;
	if (mlx_data->map[(y - cor2) / 40][x / 40] == '1'
			|| mlx_data->map[y / 40][(x - cor1) / 40] == '1')
	{
		if (mlx_data->map[y / 40][(x - cor1) / 40] != '1')
			mlx_data->player.pos.x -= cos(-mlx_data->angle) * 5;
		else if (mlx_data->map[(y - cor2) / 40][x / 40] != '1')
			mlx_data->player.pos.y -= sin(-mlx_data->angle) * 5;
		return (1);
	}
	return (0);
}

int	check_left(t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	cor1;
	int	cor2;

	x = mlx_data->player.pos.x;
	y = mlx_data->player.pos.y;
	if (mlx_data->moves.newdir.x < 0)
		cor1 = -HEADSIZE;
	else
		cor1 = HEADSIZE;
	if (mlx_data->moves.newdir.y < 0)
		cor2 = -HEADSIZE;
	else
		cor2 = HEADSIZE;
	if (mlx_data->map[(y + cor2) / 40][x / 40] == '1'
			|| mlx_data->map[y / 40][(x + cor1) / 40] == '1')
	{
		if (mlx_data->map[y / 40][(x + cor1) / 40] != '1')
			mlx_data->player.pos.x += mlx_data->moves.newdir.x * 5;
		else if (mlx_data->map[(y + cor2) / 40][x / 40] != '1')
			mlx_data->player.pos.y += mlx_data->moves.newdir.y * 5;
		return (1);
	}
	return (0);
}

int	check_right(t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	cor1;
	int	cor2;

	x = mlx_data->player.pos.x;
	y = mlx_data->player.pos.y;
	if (mlx_data->moves.newdir.x < 0)
		cor1 = -HEADSIZE;
	else
		cor1 = HEADSIZE;
	if (mlx_data->moves.newdir.y < 0)
		cor2 = -HEADSIZE;
	else
		cor2 = HEADSIZE;
	if (mlx_data->map[(y - cor2) / 40][x / 40] == '1'
			|| mlx_data->map[y / 40][(x - cor1) / 40] == '1')
	{
		if (mlx_data->map[y / 40][(x - cor1) / 40] != '1')
			mlx_data->player.pos.x -= mlx_data->moves.newdir.x * 5;
		else if (mlx_data->map[(y - cor2) / 40][x / 40] != '1')
			mlx_data->player.pos.y -= mlx_data->moves.newdir.y * 5;
		return (1);
	}
	return (0);
}

int	blocked(t_mlx_data *mlx_data, int keycode)
{
	if (keycode == K_W)
	{
		if (check_up(mlx_data))
			return (1);
	}
	else if (keycode == K_S)
	{
		if (check_down(mlx_data))
			return (1);
	}
	else if (keycode == K_A)
	{
		if (check_left(mlx_data))
			return (1);
	}
	else if (keycode == K_D)
		if (check_right(mlx_data))
			return (1);
	return (0);
}
