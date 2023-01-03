/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:21:28 by fdaumas           #+#    #+#             */
/*   Updated: 2022/12/22 16:17:10 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_ceilling(char *content, t_mlx_data *data)
{
	int			idx;
	t_color_rgb	rgb;

	verif_free_ceilling(data, content);
	idx = 0;
	while ((content[idx] >= 8 && content[idx] <= 13
			&& content[idx] != 10) || content[idx] == 32)
		idx++;
	if (!ft_isdigit(content[idx]))
	rgb.r = atoi(&content[idx + 1]);
	content = ft_strchr(content, ',');
	rgb.g = atoi(&content[1]);
	content = ft_strchr(&content[1], ',');
	rgb.b = atoi(&content[idx + 1]);
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0
		|| rgb.b > 255)
	{
		free_all_parsing(data);
		write(2, "Bad Ceilling color\n", 19);
		exit(1);
	}
	data->sol_plaf.ceilling = val_to_rgb(rgb.r, rgb.g, rgb.b);
}

void	color_ceilling(char *content, t_mlx_data *data)
{
	char	*tmp;

	tmp = ft_strchr(content, 'C');
	if (tmp == NULL)
	{
		write(2, "Ceilling color not found\n", 25);
		exit (1);
	}
	while (ft_strncmp(tmp, "C ", 2))
	{
		tmp = ft_strchr(&tmp[1], 'C');
		if (tmp == NULL)
		{
			write(2, "Ceilling color not found\n", 25);
			exit (1);
		}
	}
	get_ceilling(tmp, data);
}

void	get_floor(char *content, t_mlx_data *data)
{
	int			idx;
	t_color_rgb	rgb;

	verif_free_floor(data, content);
	idx = 0;
	while ((content[idx] >= 8 && content[idx] <= 13
			&& content[idx] != 10) || content[idx] == 32)
		idx++;
	rgb.r = atoi(&content[idx + 1]);
	content = ft_strchr(content, ',');
	rgb.g = atoi(&content[1]);
	content = ft_strchr(&content[2], ',');
	rgb.b = atoi(&content[idx + 1]);
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0 || rgb.g > 255 || rgb.b < 0
		|| rgb.b > 255)
	{
		free_all_parsing(data);
		write(2, "Bad floor color\n", 16);
		exit(1);
	}
	data->sol_plaf.floor = val_to_rgb(rgb.r, rgb.g, rgb.b);
}

void	color_floor(char *content, t_mlx_data *data)
{
	char	*tmp;

	tmp = ft_strchr(content, 'F');
	if (tmp == NULL)
	{
		write(2, "Ceilling color not found\n", 25);
		exit (1);
	}
	while (ft_strncmp(tmp, "F ", 2))
	{
		tmp = ft_strchr(&tmp[1], 'F');
		if (tmp == NULL)
		{
			write(2, "Floor color not found\n", 22);
			exit (1);
		}
	}
	get_floor(tmp, data);
}

void	all_color(char *content, t_mlx_data *data)
{
	color_ceilling(content, data);
	color_floor(content, data);
}
