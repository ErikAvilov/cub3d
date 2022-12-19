/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:26:13 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/16 15:10:52 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	key_press(int keycode, t_mlx_data *mlx_data)
{
	fill_key_tab(mlx_data, keycode);
	if (keycode == K_Y)
	{
		if (mlx_data->mouse.zone == 0)
			mlx_data->mouse.zone = 1;
		else
			mlx_data->mouse.zone = 0;
	}
	if (keycode == K_X)
		printf("pos.x: %d pos.y: %d\n", (int)mlx_data->player.pos.x, (int)mlx_data->player.pos.y);
	if (keycode == 53)
		mlx_close(mlx_data);
	return (1);
}

int	key_release(int keycode, t_mlx_data *mlx_data)
{
	empty_key_tab(mlx_data, keycode);
	return (0);
}

int	is_pressed(int	*keytab, int keycode)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (keytab[i] == keycode)
			return (1);
	}
	return (0);
}
