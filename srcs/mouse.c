/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:11:01 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/07 12:56:04 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	mouse_press(int button, int x, int y, t_mlx_data *mlx_data)
{
	if (button == LMB)
	{
		mlx_data->tableau.tab[y / 40][x / 40] = 0;
		draw_damier(mlx_data, WHITE);
	}
	else if (button == RMB)
	{
		mlx_data->tableau.tab[y / 40][x / 40] = 1;
		draw_damier(mlx_data, WHITE);
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
	return (0);
}
