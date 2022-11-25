/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:52:21 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/25 23:00:43 by eavilov          ###   ########.fr       */
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

int			mouse_press(int button, int x, int y, t_mlx_data *mlx_data);
int			mouse_release(int button, int x, int y, t_mlx_data *mlx_data);
int			mouse_move(int x, int y, t_mlx_data *mlx_data);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		fill_key_tab(t_mlx_data *mlx_data, int keycode);
void		empty_key_tab(t_mlx_data *mlx_data, int keycode);

void		damier_tab_init(t_mlx_data *mlx_data);
void		player_init(t_mlx_data *mlx_data);
void		window_init(t_mlx_data *mlx_data);
void		value_init(t_mlx_data *mlx_data);

void		draw_median(t_mlx_data *mlx_data);
void		draw_square(t_mlx_data *mlx_data, int x, int y, int color);
void		draw_damier(t_mlx_data *mlx_data, int color);
void		draw_line(t_mlx_data *mlx_data);

void		ft_bresenham(t_mlx_data *mlx_data, int x, int y, int color);
void		init_bresenham(t_mlx_data *mlx_data, int x, int y);
void		init_angle(t_mlx_data *mlx_data);

void		update_angle(t_mlx_data *mlx_data, int direction);

void		bottom_right(t_mlx_data *mlx_data, int x, int y, int color);
void		bottom_left(t_mlx_data *mlx_data, int x, int y, int color);
void		top_left(t_mlx_data *mlx_data, int x, int y, int color);
void		top_right(t_mlx_data *mlx_data, int x, int y, int color);

t_vector_2d	dda(t_mlx_data *mlx_data, int x, int y);

#endif
