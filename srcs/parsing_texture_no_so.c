#include "parsing.h"

void	get_path_no(char *content, t_mlx_data *data)
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
	data->paths[0] = ft_substr(content, idx, idx_len);
}

void	no_path(char *content, t_mlx_data *data)
{
	char	*tmp;

	tmp = ft_strchr(content, 'N');
	if (tmp == NULL)
	{
		write(2, "North texture not found\n", 24);
		exit (1);
	}
	while (ft_strncmp(tmp, "NO ", 3))
	{
		tmp = ft_strchr(&tmp[1], 'N');
		if (tmp == NULL)
		{
			write(2, "North texture not found\n", 24);
			exit (1);
		}
	}
	get_path_no(tmp, data);
}

void	get_path_so(char *content, t_mlx_data *data)
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
	data->paths[1] = ft_substr(content, idx, idx_len);
}

void	so_path(char *content, t_mlx_data *data)
{
	char *tmp;

	tmp = ft_strchr(content, 'S');
	if (tmp == NULL)
	{
		write(2, "South texture not found\n", 24);
		exit (1);
	}
	while (ft_strncmp(tmp, "SO ", 3))
	{
		tmp = ft_strchr(&tmp[1], 'S');
		if (tmp == NULL)
		{
			write(2, "South texture not found\n", 24);
			exit (1);
		}
	}
	get_path_so(tmp, data);
}

void	all_textures_path(char *content, t_mlx_data *data)
{
	no_path(content, data);
	so_path(content, data);
	we_path(content, data);
	ea_path(content, data);
	check_texture_path(data);
}
