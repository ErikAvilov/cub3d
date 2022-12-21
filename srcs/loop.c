/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:22:09 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/21 14:04:33 by eavilov          ###   ########.fr       */
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

int		get_tex(t_mlx_data *mlx_data, t_vector_2f *ray, t_textures *text)
{
	double perp_angle = PI2 - ray->angle + get_angle(mlx_data, mlx_data->player.pos, mlx_data->moves.newdir);
	double	hit_len = ray->perp_len * 0.5f * 2400 / sin(ray->angle);
	t_vector_2f	wall = vision_limit(mlx_data->player.pos, ray->angle, ray->length);
	float	cell_pos;
	if (ray->hit == 1 || ray->hit == 3)
		cell_pos = wall.y - (int)(wall.y / 40) * 40;
	else
		cell_pos = wall.x - (int)(wall.x / 40) * 40;

	if (ray->hit == 3 || ray->hit == 2)
		cell_pos = cell_pos / 40;
	else
		cell_pos = 1.0f - cell_pos / 40;
	int tex_x = cell_pos * text->width;
	return (tex_x);
}

void	draw_wall(t_mlx_data *mlx_data, int side, t_vector_2f *vector, float slice)
{
	int	y;
	int	stripe;
	double	tx_y;

	y = mlx_data->display.tl.y;
	mlx_data->display.tex = get_tex(mlx_data, vector, &mlx_data->textures[side]);
	mlx_data->display.step = mlx_data->textures[side].height / slice;
	while (y < mlx_data->display.br.y)
	{
		if (y < 0)
		{
			tx_y += -y * mlx_data->display.step;
			y = 0;
		}
		if (y >= RES_Y)
			break ;
		if (y >= 0 && y < RES_Y)
		{
			stripe = mlx_data->display.tl.x;
			while (stripe < mlx_data->display.br.x)
			{
				int col = texture_pixel_color(&mlx_data->textures[side], mlx_data->display.tex, tx_y);
				my_mlx_pixel_put(&mlx_data->img, stripe, y, col);
				stripe++;
			}
		}
		tx_y += mlx_data->display.step;
		y++;
	}
}

void	manage_wall(t_mlx_data *mlx_data, t_vector_2f *vector, float slice)
{
	if (vector->side_hit.x == 0 && vector->side_hit.y == -1)
	{
		vector->hit = 2;
		draw_wall(mlx_data, 1, vector, slice);
	}
	else if (vector->side_hit.x == 1 && vector->side_hit.y == 0)
	{
		vector->hit = 3;
		draw_wall(mlx_data, 3, vector, slice);
	}
	else if (vector->side_hit.x == -1 && vector->side_hit.y == 0)
	{
		vector->hit = 1;
		draw_wall(mlx_data, 2, vector, slice);
	}
	else if (vector->side_hit.x == 0 && vector->side_hit.y == 1)
	{
		vector->hit = 0;
		draw_wall(mlx_data, 0, vector, slice);
	}
}

void	display_terrain(t_mlx_data *mlx_data)
{
	float		slice_height;
	int			slice_width;
	int			i;

	i = -1;
	slice_width = RES_X / mlx_data->rays.amount;
	while (++i < mlx_data->rays.amount)
	{
		slice_height = 1.0f / mlx_data->vector[i].perp_len;
		slice_height = slice_height * RES_Y;
		slice_height = slice_height * 40;
		mlx_data->display.tl.x = i * slice_width;
		mlx_data->display.tl.y = (RES_Y / 2) - (slice_height / 2); 
		mlx_data->display.br.x = i * slice_width + slice_width;
		mlx_data->display.br.y = (RES_Y / 2) + (slice_height / 2);
		manage_wall(mlx_data, &mlx_data->vector[i], slice_height);
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
		mlx_data->img.image, 0, 0);
	return (0);
}
