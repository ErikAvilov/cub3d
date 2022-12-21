#include "parsing.h"

int		is_char_map(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	else if (c == '\n')
		return (3);
	return (0);
}

char	**map(char	*content, t_mlx_data *data)
{
	int		idx;
	int		player;

	player = 0;
	idx = ft_strlen(content) - 1;
	while(is_char_map(content[idx]) > 0)
	{
		if (is_char_map(content[idx]) == 2)
		{
			if (player == 1)
				free_2_player(data);
			player = 1;
			data->direction = content[idx];
		}
		else if (is_char_map(content[idx]) == 3
			&& is_char_map(content[idx - 1]) == 3)
			break;
		idx--;
	}
	while(content[idx] != '\n')
		idx++;
	return(ft_split(&content[idx + 1], '\n'));
}

void	create_map(int nb_line, int len_max, char **map, t_mlx_data *data)
{
	int idx;

	idx = 0;
	data->map = malloc(sizeof(char *) * nb_line + 1);
	if (!data->map)
		free_map(map, data, 1);
	data->map[nb_line] = NULL;
	while (map[idx])
	{
		data->map[idx] = strcomplete(map[idx], len_max);
		if (data->map[idx] == NULL)
		{
			while (idx > 0)
			{
				idx--;
				free(data->map[idx]);
			}
			free(data->map);
			free_map(map, data, 1);
		}
		idx++;
	}
}

void	get_map(char **map, t_mlx_data *data)
{
	int	index_line;
	int	len_line;
	int	len_max;

	index_line = 0;
	len_max = 0;
	while(map[index_line])
	{
		len_line = 0;
		while(map[index_line][len_line])
			len_line++;
		if (len_line > len_max)
			len_max = len_line;
		index_line++;
	}
	create_map(index_line, len_max, map, data);
	free_map(map, data, 0);
}

void	parsing_map(char *content, t_mlx_data *data)
{
	char	**init_map;

	init_map = map(content, data);
	if (ft_strlen(init_map[0]) == 0 || init_map == NULL)
	{
		free_all_parsing(data);
		write(2, "no map\n", 7);
		exit(1);
	}
	get_map(init_map, data);
	check_map(data);
	for(int i = 0;data->map[i];i++)
		printf("map = %s\n", data->map[i]);
}