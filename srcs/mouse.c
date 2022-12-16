/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:11:01 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/16 12:32:32 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	mouse_press(int button, int x, int y, t_mlx_data *mlx_data)
{
	if (button == LMB)
	{
		mlx_data->map[y / 40][x / 40] = '0';
	}
	else if (button == RMB)
	{
		mlx_data->map[y / 40][x / 40] = '1';
	}
	else if (button == MMB)
	{
		mlx_data->player.pos.x = x;
		mlx_data->player.pos.y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx_data *mlx_data)
{
	return (0);
}

int	mouse_move(int x, int y, t_mlx_data *mlx_data)
{
	if ((x > 1260 || x < 20) || (x < 740 && x > 540) || (y > 700 || y < 20))
		mlx_data->mouse.x = -1;
	else
		mlx_data->mouse.x = x;
	return (0);
}
