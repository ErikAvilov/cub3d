/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:38:16 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 09:02:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

float	ft_abs(float nbr)
{
	if (nbr < 0.0f)
		return (-nbr);
	else
		return (nbr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= RES_X || y >= RES_Y)
		dprintf(1, "x: %d y: %d\n", x, y);
	if (x < 0 || y < 0)
		dprintf(1, "x: %d y: %d\n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_key_tab(t_mlx_data *mlx_data, int keycode)
{
	int	i;

	i = -1;
	while (++i < mlx_data->moves.fingers)
	{
		if (mlx_data->moves.key[i] == -1)
		{
			mlx_data->moves.key[i] = keycode;
			return ;
		}
	}
}

void	empty_key_tab(t_mlx_data *mlx_data, int keycode)
{
	int	i;

	i = -1;
	while (++i < mlx_data->moves.fingers)
	{
		if (mlx_data->moves.key[i] == keycode)
		{
			mlx_data->moves.key[i] = -1;
			return ;
		}
	}
}

int	mlx_close(t_mlx_data *mlx_data)
{
	free_data_map(mlx_data, NULL);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
	return (0);
}
