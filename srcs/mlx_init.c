/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:48:15 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 09:58:24 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

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

void	value_init(t_mlx_data *mlx_data, char **av)
{
	int			i;
	t_vector_2d	dir;

	i = -1;
	mlx_data->moves.fingers = 10;
	while (++i < mlx_data->moves.fingers)
		mlx_data->moves.key[i] = -1;
	mlx_data->mouse.x = -1;
	mlx_data->mouse.zone = 0;
	if (parsing_file(av[1], mlx_data))
		exit(1);
	dir = player_init(mlx_data);
	screen_init(mlx_data);
	mlx_data->vector[0] = dda(mlx_data, mlx_data->player.pos.x + dir.x,
			mlx_data->player.pos.y + dir.y, 0);
	mlx_data->angle = get_angle(mlx_data, mlx_data->player.pos,
			mlx_data->vector[0]);
	mlx_data->moves.newdir.x = cos(-mlx_data->angle) * cos(-PI2)
		- sin(-mlx_data->angle) * sin(-PI2);
	mlx_data->moves.newdir.y = cos(-mlx_data->angle) * sin(-PI2)
		+ sin(-mlx_data->angle) * cos(-PI2);
}

void	textures_init(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_data->textures[i].image = mlx_xpm_file_to_image(mlx_data->mlx,
				mlx_data->paths[i], &mlx_data->textures[i].width,
				&mlx_data->textures[i].height);
		if (!mlx_data->textures[i].image)
			exit (printf("image not found\n"));
		mlx_data->textures[i].text_adr
			= mlx_get_data_addr(mlx_data->textures[i].image,
				&mlx_data->textures[i].bits_per_pixel,
				&mlx_data->textures[i].line_length,
				&mlx_data->textures[i].endian);
		if (!mlx_data->textures[i].text_adr)
			exit(printf("addr not found\n"));
		mlx_data->textures[i].side = i;
		i++;
	}
}

void	check_args(int ac)
{
	if (ac != 2)
		exit (printf("wrong arg amount\n"));
}

void	window_init(t_mlx_data *mlx_data, int ac, char **av)
{
	check_args(ac);
	value_init(&*mlx_data, av);
	mlx_data->mlx = mlx_init();
	textures_init(mlx_data);
	mlx_data->win = mlx_new_window(mlx_data->mlx, mlx_data->res.res[0],
			mlx_data->res.res[1], "cub");
	mlx_do_key_autorepeatoff(mlx_data->mlx);
}
