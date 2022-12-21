#include "parsing.h"

void	free_map(char **map, t_mlx_data *data, int fail)
{
	int idx;

	idx = 0;
	while(map[idx])
	{
		free(map[idx]);
		idx++;
	}
	free(map);
	if (fail == 1)
	{
		free_all_parsing(data);
		write(2, "fail malloc\n", 12);
		exit(1);
	}
}

void	free_data_map(t_mlx_data *data, char *msg)
{
	int idx;

	idx = 0;
	while(data->map[idx])
	{
		free(data->map[idx]);
		idx++;
	}
	free(data->map);
	free_all_parsing(data);
	if(msg != NULL)
	{
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
}