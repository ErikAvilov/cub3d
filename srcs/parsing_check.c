#include "parsing.h"

int	check_format(char *file, char *format, int len)
{
	int	idx;

	idx = 0;
	while (file[idx])
	{
		if (!ft_strncmp(&file[idx], format, len))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

void	check_texture_path(t_mlx_data *data)
{
	int error;

	error = 0;
	if (check_format(data->paths[0], ".xpm", 4))
	{
		write(2, "Bad NO format\n", 14);
		error++;
	}
	if (check_format(data->paths[1], ".xpm", 4))
	{
		write(2, "Bad SO format\n", 14);
		error++;
	}
	if (check_format(data->paths[2], ".xpm", 4))
	{
		write(2, "Bad EA format\n", 14);
		error++;
	}
	if (check_format(data->paths[3], ".xpm", 4))
	{
		write(2, "Bad WE format\n", 14);
		error++;
	}
	if (error > 0)
		exit(error);
}

int	is_0(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_line(t_mlx_data *data, int line)
{
	int	idx;

	idx = 0;
	while (data->map[line][idx])
	{
		if(is_0(data->map[line][idx]))
			free_data_map(data, "map not closed\n");
		idx++;
	}
}

void	check_map(t_mlx_data *data)
{
	int		idx_line;
	int		idx_char;

	idx_line = 0;
	while (data->map[idx_line])
		idx_line++;
	idx_line--;
	check_line(data, idx_line);
	check_line(data, 0);
	while(idx_line > 1)
	{
		idx_char = 1;
		idx_line--;
		while(data->map[idx_line][idx_char])
		{
			if (is_0(data->map[idx_line][idx_char]))
				if (data->map[idx_line][idx_char + 1] == ' '
				|| data->map[idx_line][idx_char - 1] == ' '
				|| data->map[idx_line + 1][idx_char] == ' '
				|| data->map[idx_line - 1][idx_char] == ' ')
					free_data_map(data, "map not closed\n");
			idx_char++;
		}
	}
}