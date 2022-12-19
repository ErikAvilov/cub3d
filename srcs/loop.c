/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/19 14:33:27 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	send_rays(t_mlx_data *mlx_data)
{
	int	i;

	i = -1;
	draw_damier(mlx_data, WHITE);
	while (++i < 1280)
	{
		if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == -1)
			ft_bresenham(mlx_data, mlx_data->vector[i].x,
				mlx_data->vector[i].y, RED);
		else if (mlx_data->vector[i].side_hit.x == 1 && mlx_data->vector[i].side_hit.y == 0)
			ft_bresenham(mlx_data, mlx_data->vector[i].x,
					mlx_data->vector[i].y, YELLOW);
		else if (mlx_data->vector[i].side_hit.x == -1 && mlx_data->vector[i].side_hit.y == 0)
			ft_bresenham(mlx_data, mlx_data->vector[i].x,
					mlx_data->vector[i].y, GREEN);
		else if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == 1)
			ft_bresenham(mlx_data, mlx_data->vector[i].x,
					mlx_data->vector[i].y, BLUE);
	}
}

void	draw_wall(t_mlx_data *mlx_data, t_vector_2d tl, t_vector_2d br, int color)
{
	int	y;
	int	stripe;

	y = tl.y;
	double tex_y = 0;
	int tex_x = 0;
	while (y < br.y)
	{
		if (y >= RES_Y)
			break ;
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

int	texture_pixel_color(t_textures *text, int x, int y)
{
	int	color;

	if (text == NULL)
		exit(printf("ERROR\n"));
	color = (*(int *)text->text_adr + (y * text->line_length) + (x * text->bits_per_pixel / 8));
	return (color);
}

void	manage_wall(t_mlx_data *mlx_data, t_vector_2d tl, t_vector_2d br, int i)
{
	static int o = 0;
	int color = texture_pixel_color(&mlx_data->textures, 10, 10);
	if (o == 0)
		printf("color: %x\n", color);
	o++;
	if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == -1)
			draw_wall(mlx_data, tl, br, color);
	else if (mlx_data->vector[i].side_hit.x == 1 && mlx_data->vector[i].side_hit.y == 0)
			draw_wall(mlx_data, tl, br, YELLOW);
	else if (mlx_data->vector[i].side_hit.x == -1 && mlx_data->vector[i].side_hit.y == 0)
			draw_wall(mlx_data, tl, br, GREEN);
	else if (mlx_data->vector[i].side_hit.x == 0 && mlx_data->vector[i].side_hit.y == 1)
			draw_wall(mlx_data, tl, br, BLUE);
}

void	display_terrain(t_mlx_data *mlx_data)
{
	float		slice_height;
	int			slice_width;
	int			i;
	t_vector_2d	tl;
	t_vector_2d	br;

	i = -1;
	slice_width = RES_X / mlx_data->rays.amount;
	while (++i < mlx_data->rays.amount)
	{
		slice_height = 1.0f / mlx_data->vector[i].perp_len;
		if (slice_height > 0.39)
			slice_height = 1.0f / mlx_data->vector[i].length;
		slice_height = slice_height * RES_Y;
		slice_height = slice_height * 40;
		tl.x = i * slice_width;
		tl.y = (RES_Y / 2) - (slice_height / 2); 
		br.x = i * slice_width + slice_width;
		br.y = (RES_Y / 2) + (slice_height / 2);
		manage_wall(mlx_data, tl, br, i);
	}
}

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

void	draw_image(t_mlx_data *mlx_data)
{
	int	x = 0;
	int y = 0;
	int color = 0;
	while (y < mlx_data->textures.height)
	{
		while (x < mlx_data->textures.width)
		{
			color = texture_pixel_color(&mlx_data->textures, x, y);
			my_mlx_pixel_put(&mlx_data->img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_image2(t_mlx_data *mlx_data)
{
	int	x = 0;
	int y = 0;
	int color = 0;
	while (y < mlx_data->textures.height)
	{
		while (x < mlx_data->textures.width)
		{
			color = texture_pixel_color(&mlx_data->textures, x, y);
			my_mlx_pixel_put(&mlx_data->img, x + 200, y + 200, color);
			x++;
		}
		x = 0;
		y++;
	}
}

int	loop(t_mlx_data *mlx_data)
{
	algo_init(mlx_data);
	check_mouse_rot(mlx_data);
	check_action(mlx_data);
	//send_rays(mlx_data);
	//draw_image(mlx_data);
	//draw_image2(mlx_data);
	floor_ceiling(mlx_data);
	display_terrain(mlx_data);
	if (mlx_data->mouse.zone == 1)
		display_zone(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->img.image, 20, 20);
	return (0);
}
