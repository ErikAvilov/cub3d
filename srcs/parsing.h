/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:22:36 by fdaumas           #+#    #+#             */
/*   Updated: 2022/12/21 07:23:59 by fdaumas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "functions.h"

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
