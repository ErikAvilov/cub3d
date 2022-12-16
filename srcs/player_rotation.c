/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:13:44 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/16 11:56:18 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	rotate_left(t_mlx_data *mlx_data)
{
	if (mlx_data->angle >= 6.28)
			mlx_data->angle = 0;
	mlx_data->angle += 0.030f;
	mlx_data->moves.newdir.x = cos(-mlx_data->angle) * cos(-PI2)
		- sin(-mlx_data->angle) * sin(-PI2);
	mlx_data->moves.newdir.y = cos(-mlx_data->angle) * sin(-PI2)
		+ sin(-mlx_data->angle) * cos(-PI2);
}

void	rotate_right(t_mlx_data *mlx_data)
{
	if (mlx_data->angle <= 0)
			mlx_data->angle = PI * 2.0f;
	mlx_data->angle -= 0.030f;
	mlx_data->moves.newdir.x = cos(-mlx_data->angle) * cos(-PI2)
		- sin(-mlx_data->angle) * sin(-PI2);
	mlx_data->moves.newdir.y = cos(-mlx_data->angle) * sin(-PI2)
		+ sin(-mlx_data->angle) * cos(-PI2);
}
