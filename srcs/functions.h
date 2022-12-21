/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:52:21 by eavilov           #+#    #+#             */
/*   Updated: 2022/12/21 14:31:38 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"

int				mlx_close(t_mlx_data *mlx_data);
int				key_press(int keycode, t_mlx_data *mlx_data);
int				key_release(int keycode, t_mlx_data *mlx_data);
int				loop(t_mlx_data *mlx_data);
int				is_pressed(int	*keytab, int keycode);

int				mouse_press(int button, int x, int y, t_mlx_data *mlx_data);
int				mouse_release(int button, int x, int y, t_mlx_data *mlx_data);
int				mouse_move(int x, int y, t_mlx_data *mlx_data);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			fill_key_tab(t_mlx_data *mlx_data, int keycode);
void			empty_key_tab(t_mlx_data *mlx_data, int keycode);
float			get_angle(t_mlx_data *mlx_data, t_vector_2f player, t_vector_2f dest);
float			ft_abs(float nbr);

t_vector_2d		player_init(t_mlx_data *mlx_data);
void			window_init(t_mlx_data *mlx_data);
void			value_init(t_mlx_data *mlx_data);

void			draw_square(t_mlx_data *mlx_data, int x, int y, int color);
void			draw_damier(t_mlx_data *mlx_data, int color);
void			draw_line(t_mlx_data *mlx_data);
void			ft_bresenham(t_mlx_data *mlx_data, int x, int y, int color);
void			init_bresenham(t_mlx_data *mlx_data, int x, int y);
void			bottom_left(t_mlx_data *mlx_data, int x, int y, int color);
void			bottom_right(t_mlx_data *mlx_data, int x, int y, int color);
void			top_left(t_mlx_data *mlx_data, int x, int y, int color);
void			top_right(t_mlx_data *mlx_data, int x, int y, int color);
void			send_rays(t_mlx_data *mlx_data);
int				bunch_of_ifs(t_mlx_data *mlx_data,
					t_vector_2f limit, t_vector_2f map);
int				view_limit(t_mlx_data *mlx_data,
					t_vector_2f limit, t_vector_2f map);

void			display_zone(t_mlx_data *mlx_data);

double			find_angle(t_mlx_data *mlx_data, int x, int y);

t_vector_2f		vision_limit(t_vector_2f origin, double angle, int limit);
t_vector_2f		lerp(t_vector_2f start, t_vector_2f end, float i);
t_vector_2f		dda(t_mlx_data *mlx_data, int x, int y);
int				collided(t_mlx_data *mlx_data, int x, int y);

void			dda_init(t_mlx_data *mlx_data, int x, int y);
void			dda_init2(t_mlx_data *mlx_data);
void			dda_init3(t_mlx_data *mlx_data);

void			algo_init(t_mlx_data *mlx_data);
void			rays_init(t_mlx_data *mlx_data);

int				check_up(t_mlx_data *mlx_data);
int				check_down(t_mlx_data *mlx_data);
int				check_left(t_mlx_data *mlx_data);
int				check_right(t_mlx_data *mlx_data);
void			check_mouse_rot(t_mlx_data *mlx_data);
int				blocked(t_mlx_data *mlx_data, int keycode);

void			move_front(t_mlx_data *mlx_data, float speed);
void			move_behind(t_mlx_data *mlx_data, float speed);
void			strafe_left(t_mlx_data *mlx_data, float speed);
void			strafe_right(t_mlx_data *mlx_data, float speed);
void			rotate_left(t_mlx_data *mlx_data);
void			rotate_right(t_mlx_data *mlx_data);

void			check_action(t_mlx_data *mlx_data);
int				blocked(t_mlx_data *mlx_data, int keycode);

void			manage_wall(t_mlx_data *mlx_data, t_vector_2f *vector, float slice);
void			display_terrain(t_mlx_data *mlx_data);
void			floor_ceiling(t_mlx_data *mlx_data);

int				texture_pixel_color(t_textures *text, int x, int y);
unsigned long	val_to_rgb(t_mlx_data *mlx_data, int r, int g, int b);

void	check_malloc(t_mlx_data *data, char *content);
int		check_format(char *file, char *format, int len);
void	check_texture_path(t_mlx_data *data);
void	check_map(t_mlx_data *data);

char	*ft_strjoin_cub(char *s1, char *s2);
int		open_verification(char *file, char *msg);
char	*read_all_file(int fd);
int		parsing_file(char *file, t_mlx_data *data);

void	no_path(char *content, t_mlx_data *data);
void	so_path(char *content, t_mlx_data *data);
void	we_path(char *content, t_mlx_data *data);
void	ea_path(char *content, t_mlx_data *data);
void	all_textures_path(char *content, t_mlx_data *data);

void	all_color(char *content, t_mlx_data *data);

void	free_2_player(t_mlx_data *data);
void	parsing_map(char *content, t_mlx_data *data);
char	*strcomplete(char *str, int len);

void	verif_free_ceilling(t_mlx_data *data, char *content);
void	verif_free_floor(t_mlx_data *data, char *content);
void	free_map(char **map, t_mlx_data *data, int fail);
void	free_data_map(t_mlx_data *data, char *msg);
void	free_all_parsing(t_mlx_data *data);

#endif
