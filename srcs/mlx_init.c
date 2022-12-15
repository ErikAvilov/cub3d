/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:48:15 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/15 13:40:34 by eavilov          ###   ########.fr       */
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
				printf("%d", mlx_data->tableau.tab[y][x]);
				x++;
			}
			printf("\n");
			x = 0;
			y++;
			if (y >= 17)
				return ;
		}
		mlx_data->tableau.tab[y][x] = 1;
		printf("%d", mlx_data->tableau.tab[y][x]);
		while (++x < mlx_data->tableau.width - 1)
		{
			mlx_data->tableau.tab[y][x] = 0;
			printf("%d", mlx_data->tableau.tab[y][x]);
		}
		mlx_data->tableau.tab[y][x] = 1;
		printf("%d", mlx_data->tableau.tab[y][x]);
		printf("\n");
		x = 0;
		y++;
	}
	printf("\n");
}

int	is_char(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

t_vector_2f	set_pos(t_mlx_data *mlx_data)
{
	t_vector_2f	pos;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (mlx_data->map[y])
	{
		while (mlx_data->map[y][x])
		{
			if(is_char(mlx_data->map[y][x]))
				return (pos);
			x++;
			pos.x += 40;
		}
		pos.y += 40;
		pos.x = 0;
		x = 0;
		y++;
	}
	pos.x = RES_X / 2;
	pos.y = RES_Y / 2;
	return (pos);
}

t_vector_2d	player_init(t_mlx_data *mlx_data)
{
	t_vector_2d	dir;
	char		c;

	c = 'N';
	mlx_data->player.pos = set_pos(mlx_data);
	//mlx_data->player.pos.x = RES_X / 2;
	//mlx_data->player.pos.y = RES_Y / 2;
	mlx_data->player.dir[0] = 0;
	mlx_data->player.dir[1] = -1;
	mlx_data->player.view_dst = 100;
	if (c == 'N')
	{
		dir.x = 0;
		dir.y = -100;
	}
	else if (c == 'S')
	{
		dir.x = 0;
		dir.y = 100;
	}
	else if (c == 'E')
	{
		dir.x = 100;
		dir.y = 0;
	}
	else if (c == 'W')
	{
		dir.x = -100;
		dir.y = 0;
	}
	return (dir);
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

void	map_init(t_mlx_data *mlx_data)
{
	int		file;
	int		rd;
	char	map[1000000];
	int		i1;
	int		i2;

	file = open("maps/map2.cub", O_RDONLY);
	rd = read(file, map, 100000);
	map[rd] = '\0';
	mlx_data->map = ft_split(map, '\n');
	// while (mlx_data->map[i2])
	// {
	// 	while (cpy[i2][i1])
	// 	{
	// 		mlx_data->tableau.tab[i2][i1] = ft_atoi(&cpy[i2][i1]);
	// 		i1++;
	// 	}
	// 	i1 = 0;
	// 	i2++;
	// }
}

void	value_init(t_mlx_data *mlx_data)
{
	int			i;
	t_vector_2d	dir;

	i = -1;
	mlx_data->moves.fingers = 10;
	while (++i < mlx_data->moves.fingers)
		mlx_data->moves.key[i] = -1;
	//damier_tab_init(mlx_data);
	map_init(mlx_data);
	dir = player_init(mlx_data);
	screen_init(mlx_data);
	mlx_data->vector[0] = dda(mlx_data, mlx_data->player.pos.x + dir.x,
			mlx_data->player.pos.y + dir.y);
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
