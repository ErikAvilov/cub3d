/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:42:37 by eavilov           #+#    #+#             */
/*   Updated: 2023/01/02 11:18:05 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	get_tex(t_mlx_data *mlx_data, t_vector_2f ray, t_textures *text)
{
	t_vector_2f	wall;
	float		cell_pos;

	wall = vision_limit(mlx_data->player.pos, ray.angle, ray.length);
	if (ray.hit == 1 || ray.hit == 3)
		cell_pos = wall.y - (int)wall.y / 40 * 40;
	else
		cell_pos = wall.x - (int)wall.x / 40 * 40;
	if (ray.hit == 3 || ray.hit == 2)
		cell_pos = cell_pos / 40;
	else
		cell_pos = 1.0f - cell_pos / 40;
	return (cell_pos * text->width);
}

void	check_neg(t_mlx_data *mlx_data, int *y, double *tx_y)
{
	if (*y < 0)
	{
		*tx_y += -*y * mlx_data->display.step;
		*y = 0;
	}
}

void	draw_wall(t_mlx_data *mlx_data, int side,
			t_vector_2f vector, float slice)
{
	int		y;
	int		stripe;
	double	tx_y;
	int		color;

	tx_y = 0;
	y = mlx_data->display.tl.y - 1;
	mlx_data->display.tex = get_tex(mlx_data,
			vector, &mlx_data->textures[side]);
	mlx_data->display.step = mlx_data->textures[side].height / slice;
	while (++y < mlx_data->display.br.y)
	{
		check_neg(mlx_data, &y, &tx_y);
		if (y >= RES_Y || y < 0)
			break ;
		stripe = mlx_data->display.tl.x;
		while (stripe < mlx_data->display.br.x)
		{
			color = texture_pixel_color(&mlx_data->textures[side],
					mlx_data->display.tex, tx_y);
			my_mlx_pixel_put(&mlx_data->img, stripe, y, color);
			stripe++;
		}
		tx_y += mlx_data->display.step;
	}
}

void	manage_wall(t_mlx_data *mlx_data, t_vector_2f vector, float slice)
{
	if (vector.side_hit.x == 0 && vector.side_hit.y == -1)
	{
		vector.hit = 2;
		draw_wall(mlx_data, 1, vector, slice);
	}
	else if (vector.side_hit.x == 1 && vector.side_hit.y == 0)
	{
		vector.hit = 3;
		draw_wall(mlx_data, 3, vector, slice);
	}
	else if (vector.side_hit.x == -1 && vector.side_hit.y == 0)
	{
		vector.hit = 1;
		draw_wall(mlx_data, 2, vector, slice);
	}
	else if (vector.side_hit.x == 0 && vector.side_hit.y == 1)
	{
		vector.hit = 0;
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
		manage_wall(mlx_data, mlx_data->vector[i], slice_height);
	}
}
