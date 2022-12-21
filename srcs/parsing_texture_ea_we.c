#include "parsing.h"

void	get_path_ea(char *content, t_mlx_data *data)
{
	int		idx;
	int		idx_len;

	idx = 2;
	while ((content[idx] >= 8 && content[idx] <= 13
			&& content[idx] != 10) || content[idx] == 32)
		idx++;
	idx_len = 0;
	while (!(content[idx + idx_len] >= 8 && content[idx + idx_len] <= 13))
		idx_len++;
	data->paths[2] = ft_substr(content, idx, idx_len);
}

void	ea_path(char *content, t_mlx_data *data)
{
	char *tmp;

	tmp = ft_strchr(content, 'E');
	if (tmp == NULL)
	{
		write(2, "East texture not found\n", 23);
		exit (1);
	}
	while (ft_strncmp(tmp, "EA ", 3))
	{
		tmp = ft_strchr(&tmp[1], 'A');
		if (tmp == NULL)
		{
			write(2, "East texture not found\n", 23);
			exit (1);
		}
	}
	get_path_ea(tmp, data);
}

void	get_path_we(char *content, t_mlx_data *data)
{
	int		idx;
	int		idx_len;

	idx = 2;
	while ((content[idx] >= 8 && content[idx] <= 13
			&& content[idx] != 10) || content[idx] == 32)
		idx++;
	idx_len = 0;
	while (!(content[idx + idx_len] >= 8 && content[idx + idx_len] <= 13))
		idx_len++;
	data->paths[3] = ft_substr(content, idx, idx_len);
}

void	we_path(char *content, t_mlx_data *data)
{
	char *tmp;

	tmp = ft_strchr(content, 'W');
	if (tmp == NULL)
	{
		write(2, "West texture not found\n", 23);
		exit (1);
	}
	while (ft_strncmp(tmp, "WE ", 3))
	{
		tmp = ft_strchr(&tmp[1], 'W');
		if (tmp == NULL)
		{
			write(2, "West texture not found\n", 23);
			exit (1);
		}
	}
	get_path_we(tmp, data);
}

void	check_malloc(t_mlx_data *data, char *content)
{
	int	fail;
	int	idx;

	idx = 0;
	fail = 0;
	while(idx < 4)
	{
		if (data->paths[idx] == NULL)
			fail = 1;
		idx++;
	}
	if(fail)
	{
		idx = 0;
		while(idx < 4)
		{
			if (data->paths[idx] != NULL)
				free(data->paths[idx]);
			idx++;
		}
	}
	free(content);
	write(2, "fail malloc\n", 12);
	exit(1);
}
