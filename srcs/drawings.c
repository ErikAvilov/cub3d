/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:57 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 06:31:17 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	display_zone(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while (i < RES_Y)
	{
		my_mlx_pixel_put(&mlx_data->img, 740, i, PINK);
		my_mlx_pixel_put(&mlx_data->img, 540, i, PINK);
		i++;
	}
}

void	floor_ceiling(t_mlx_data *mlx_data)
{
	int				x;
	int				y;

	x = -1;
	y = 0;
	while (y < (RES_Y / 2))
	{
		while (++x < RES_X)
			my_mlx_pixel_put(&mlx_data->img, x, y, mlx_data->sol_plaf.ceilling);
		x = 0;
		y++;
	}
	x = -1;
	while (y < RES_Y)
	{
		while (++x < RES_X)
			my_mlx_pixel_put(&mlx_data->img, x, y, mlx_data->sol_plaf.floor);
		x = 0;
		y++;
	}
}
