/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:52:21 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/18 14:24:18 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

int			mlx_close(t_mlx_data *mlx_data);
int			key_press(int keycode, t_mlx_data *mlx_data);
int			key_release(int keycode, t_mlx_data *mlx_data);
int			loop(t_mlx_data *mlx_data);
int			is_pressed(int	*keytab, int keycode);

void		fill_key_tab(t_mlx_data *mlx_data, int keycode);
void		empty_key_tab(t_mlx_data *mlx_data, int keycode);

void		window_init(t_mlx_data *mlx_data);
void		value_init(t_mlx_data *mlx_data);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_median(t_mlx_data *mlx_data);

void		bresenham(t_mlx_data *mlx_data, int x, int y, int color);
void		init_bresenham(t_mlx_data *mlx_data, int x, int y);

#endif
