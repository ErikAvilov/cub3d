/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/09 13:21:38 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	send_rays(t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	while (++i < 1280)
	{
		// if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == -1)
		// 	ft_bresenham(mlx_data, mlx_data->vector[i].x,
		// 		mlx_data->vector[i].y, RED);
		// else if (mlx_data->vector[i].side_hit.x == 1 && mlx_data->vector[i].side_hit.y == 0)
		// 	ft_bresenham(mlx_data, mlx_data->vector[i].x,
		// 			mlx_data->vector[i].y, YELLOW);
		// else if (mlx_data->vector[i].side_hit.x == -1 && mlx_data->vector[i].side_hit.y == 0)
		// 	ft_bresenham(mlx_data, mlx_data->vector[i].x,
		// 			mlx_data->vector[i].y, GREEN);
		// else if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == 1)
		// 	ft_bresenham(mlx_data, mlx_data->vector[i].x,
		// 			mlx_data->vector[i].y, BLUE);
		ft_bresenham(mlx_data, mlx_data->vector[i].x,
		 			mlx_data->vector[i].y, PURPLE);
	}
}

void	draw_wall(t_mlx_data *mlx_data, t_vector_2d tl, t_vector_2d br, int color)
{
	int	y;
	int	stripe;

	y = tl.y;
	while (y < br.y)
	{
		if (y >= RES_Y)
		{
			printf("too big\n");
			break ;
		}
		if (y < 0)
			printf("error?\n");
		if (y >= 0 && y < RES_Y)
		{
			stripe = tl.x;
			while (stripe < br.x)
			{
				my_mlx_pixel_put(&mlx_data->img, stripe, y, color);
				stripe++;
			}
		}
		y++;
	}
}

void	display_terrain(t_mlx_data *mlx_data)
{
	float		slice_height;
	const int			slice_width = RES_X / mlx_data->rays.amount;;
	int			i;
	t_vector_2d	tl;
	t_vector_2d	br;

	i = -1;
	while (++i < mlx_data->rays.amount)
	{
		if (mlx_data->vector[i].length < 0)
			printf("mdr\n");
		slice_height = 1.0f / mlx_data->vector[i].length;
		slice_height = slice_height * RES_Y;
		slice_height = slice_height * 20;
		tl.x = i * slice_width;
		tl.y = (RES_Y / 2) - (slice_height / 2); 
	
		br.x = i * slice_width + slice_width;
		br.y = (RES_Y / 2) + (slice_height / 2);
		if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == -1)
				draw_wall(mlx_data, tl, br, RED);
		else if (mlx_data->vector[i].side_hit.x == 1 && mlx_data->vector[i].side_hit.y == 0)
				draw_wall(mlx_data, tl, br, YELLOW);
		else if (mlx_data->vector[i].side_hit.x == -1 && mlx_data->vector[i].side_hit.y == 0)
				draw_wall(mlx_data, tl, br, GREEN);
		else if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == 1)
				draw_wall(mlx_data, tl, br, BLUE);
	}
}

int	loop(t_mlx_data *mlx_data)
{
	algo_init(mlx_data);
	draw_damier(mlx_data, WHITE);
	check_action(mlx_data);
	send_rays(mlx_data);
	//display_terrain(mlx_data);
	//printf("player at x: %d y: %d\n", (int)mlx_data->player.pos.x, (int)mlx_data->player.pos.y);
	//ft_bresenham(mlx_data, mlx_data->vector[0].x, mlx_data->vector[0].y, WHITE);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img.image, 0, 0);
	return (0);
}
