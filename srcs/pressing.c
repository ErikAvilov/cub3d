/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:26:13 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 14:11:15 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	key_press(int keycode, t_mlx_data *mlx_data)
{
	static int	x = 0;
	int temp = 0;
	int	times = -1;
	int y = 0;
	fill_key_tab(mlx_data, keycode);
	if (keycode == K_R)
	{
		if (x >= mlx_data->res.res[0])
			return (0);
		while (++times < 20)
		{
			while (temp < mlx_data->res.res[1])
			{
				my_mlx_pixel_put(&mlx_data->img, x, y, WHITE);
				y++;
				temp++;
			}
			temp = 0;
			y = 0;
			x++;
		}
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img.image, 0, 0);
		x += 80;
	}
	if (keycode == K_C)
		printf("coords - x: %d y: %d\n", mlx_data->coords.x, mlx_data->coords.y);
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
	while (++i < 8)
	{
		if (keytab[i] == keycode)
			return (1);
	}
	return (0);
}
