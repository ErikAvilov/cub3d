/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:59:39 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/21 17:01:22 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

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
			if (is_char(mlx_data->map[y][x]))
			{
				pos.x += 20;
				pos.y += 20;
				return (pos);
			}
			x++;
			pos.x += 40;
		}
		pos.y += 40;
		pos.x = 0;
		x = 0;
		y++;
	}
	exit(write(2, "player not found\n", 18));
}

t_vector_2d	player_init(t_mlx_data *mlx_data)
{
	t_vector_2d	dir;
	char		c;

	dir.x = 0;
	dir.y = 0;
	c = mlx_data->direction;
	mlx_data->player.pos = set_pos(mlx_data);
	mlx_data->player.view_dst = 100;
	if (c == 'N')
		dir.y = -100;
	else if (c == 'S')
		dir.y = 100;
	else if (c == 'E')
		dir.x = 100;
	else if (c == 'W')
		dir.x = -100;
	return (dir);
}
