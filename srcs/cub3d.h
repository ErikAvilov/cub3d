/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:51:43 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 13:57:57 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "defines.h"
# include "../libx/minilibx_opengl_20191021/mlx.h"

typedef struct s_mlx_res
{
	int		res[2];
	int		center_x;
	int		center_y;
}	t_mlx_res;

typedef struct s_mlx_coords
{
	int		x;
	int		y;
}	t_mlx_coords;

typedef struct s_mlx_moves
{
	int		key[10];
	int		fingers;
}	t_mlx_moves;

typedef struct s_data
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_bresenham
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	err;
	int	e2;
}	t_bresenham;


typedef struct s_mlx_data
{
	void				*mlx;
	void				*win;
	void				*floor;
	t_mlx_coords		coords;
	t_mlx_res			res;
	t_mlx_moves			moves;
	t_data				img;
	t_bresenham			bres_val;
}	t_mlx_data;

#endif
