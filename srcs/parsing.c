/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:20:47 by fdaumas           #+#    #+#             */
/*   Updated: 2022/12/21 07:23:59 by fdaumas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strjoin_cub(char *s1, char *s2)
{
	char	*ns;

	if (s1 == NULL)
	{
		ns = ft_strdup(s2);
		return (ns);
	}
	ns = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ns)
		return (NULL);
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		ns[0] = '\0';
	else
	{
		ft_strlcpy(ns, s1, ft_strlen(s1) + 1);
		ft_strlcpy(&ns[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
		free(s1);
	}
	return (ns);
}

int	open_verification(char *file, char *msg)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		write(2, "arg is a directory\n", 19);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(msg);
		exit(1);
	}
	return (fd);
}

char	*read_all_file(int fd)
{
	int		end_read;
	char	buf[1024];
	char	*file;

	file = NULL;
	end_read = 1024;
	while (end_read == 1024)
	{
		end_read = read(fd, buf, 1024);
		buf[end_read] = '\0';
		file = ft_strjoin_cub(file, buf);
		if (file == NULL)
			exit (write(2, "fail malloc\n", 12));
	}
	return (file);
}

int	parsing_file(char *file, t_mlx_data *data)
{
	char	*content_file;

	if (check_format(file, ".cub\0", 5) == 1)
		return (write(2, "Bad map format\n", 15));
	content_file = read_all_file(open_verification(file, file));
	all_textures_path(content_file, data);
	free(data->paths[3]);
	data->paths[3] = NULL;
	check_malloc(data, content_file);
	all_color(content_file, data);
	parsing_map(content_file, data);
	free(content_file);
	return (0);
}

int	main(void)
{
	t_mlx_data	data;

	if (parsing_file("./map.cub", &data))
		return (1);
	write(1, data.paths[0], ft_strlen(data.paths[0]));
	ft_putchar(10);
	write(1, data.paths[1], ft_strlen(data.paths[1]));
	ft_putchar(10);
	write(1, data.paths[2], ft_strlen(data.paths[2]));
	ft_putchar(10);
	write(1, data.paths[3], ft_strlen(data.paths[3]));
	ft_putchar(10);
	printf("ceilling val = %zu\n", data.sol_plaf.ceilling);
	printf("floor val = %zu\n", data.sol_plaf.floor);
	for(int i = 0;data.map[i];i++)
		printf("map = %s\n", data.map[i]);
	free_data_map(&data, NULL);
	return (0);
}
