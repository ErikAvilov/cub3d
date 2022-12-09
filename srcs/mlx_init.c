/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:48:15 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/09 12:38:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	damier_tab_init(t_mlx_data *mlx_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_data->tableau.height = 18;
	mlx_data->tableau.width = 32;
	while (y < mlx_data->tableau.height)
	{
		if (y == 0 || y == 17)
		{
			while (x < mlx_data->tableau.width)
			{
				mlx_data->tableau.tab[y][x] = 1;
				x++;
			}
			x = 0;
			y++;
			if (y >= 17)
				return ;
		}
		mlx_data->tableau.tab[y][x] = 1;
		while (++x < mlx_data->tableau.width - 1)
			mlx_data->tableau.tab[y][x] = 0;
		mlx_data->tableau.tab[y][x] = 1;
		x = 0;
		y++;
	}
}

void	player_init(t_mlx_data *mlx_data)
{
	mlx_data->player.pos.x = RES_X / 2;
	mlx_data->player.pos.y = RES_Y / 2;
	mlx_data->player.dir[0] = 0;
	mlx_data->player.dir[1] = -1;
	mlx_data->player.view_dst = 100;
}

void	screen_init(t_mlx_data *mlx_data)
{
	mlx_data->img.bits_per_pixel = 0;
	mlx_data->img.line_length = 0;
	mlx_data->img.endian = 0;
	mlx_data->res.res[0] = RES_X;
	mlx_data->res.res[1] = RES_Y;
	mlx_data->res.center_x = RES_X / 2;
	mlx_data->res.center_y = RES_Y / 2;
	mlx_data->rays.opposite = tan(OPPOSITE) * 800;
	mlx_data->rays.amount = 1280;
	mlx_data->rays.gap = 1 / (mlx_data->rays.amount * 0.5);
}

void	value_init(t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	mlx_data->moves.fingers = 10;
	while (++i < mlx_data->moves.fingers)
		mlx_data->moves.key[i] = -1;
	damier_tab_init(mlx_data);
	player_init(mlx_data);
	screen_init(mlx_data);
	mlx_data->vector[0] = dda(mlx_data, mlx_data->player.pos.x,
			mlx_data->player.pos.y - 100);
	mlx_data->angle = find_angle(mlx_data, mlx_data->vector[0].x,
			mlx_data->vector[0].y);
	mlx_data->moves.newdir.x = cos(-mlx_data->angle) * cos(-PI2)
		- sin(-mlx_data->angle) * sin(-PI2);
	mlx_data->moves.newdir.y = cos(-mlx_data->angle) * sin(-PI2)
		+ sin(-mlx_data->angle) * cos(-PI2);
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
