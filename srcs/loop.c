/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 08:28:17 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	check_mouse_rot(t_mlx_data *mlx_data)
{
	if (mlx_data->mouse.x != -1)
	{
		if (mlx_data->mouse.x > RES_X / 2)
			rotate_right(mlx_data);
		if (mlx_data->mouse.x < RES_X / 2)
			rotate_left(mlx_data);
	}
}

int	loop(t_mlx_data *mlx_data)
{
	rays_init(mlx_data);
	check_mouse_rot(mlx_data);
	floor_ceiling(mlx_data);
	display_terrain(mlx_data);
	if (mlx_data->mouse.zone == 1)
		display_zone(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img.image, 0, 0);
	check_action(mlx_data);
	return (0);
}
