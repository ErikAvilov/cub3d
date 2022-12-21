#include "parsing.h"

void	free_all_parsing(t_mlx_data *data)
{
	free(data->paths[0]);
	free(data->paths[1]);
	free(data->paths[2]);
	free(data->paths[3]);
}

void	verif_free_ceilling(t_mlx_data *data, char *content)
{
	int	idx;
	int	count_point;
	int	count_nb;

	idx = 0;
	count_point = 0;
	count_nb = 0;
	while (content[idx] != '\n')
	{
		if (ft_isdigit(content[idx]))
		{
			count_nb++;
			while (ft_isdigit(content[idx]))
				idx++;
		}
		if (content[idx] == ',')
			count_point++;
		if (content[idx] != '\n')
			idx++;
	}
	if (count_point == 2 && count_nb == 3)
		return ;
	free_all_parsing(data);
	write(2, "Bad Ceilling color\n", 19);
	exit(1);
}

void	verif_free_floor(t_mlx_data *data, char *content)
{
	int	idx;
	int	count_point;
	int	count_nb;

	idx = 0;
	count_point = 0;
	count_nb = 0;
	while (content[idx] != '\n')
	{
		if (ft_isdigit(content[idx]))
		{
			count_nb++;
			while (ft_isdigit(content[idx]))
				idx++;
		}
		if (content[idx] == ',')
			count_point++;
		if (content[idx] != '\n')
			idx++;
	}
	if (count_point == 2 && count_nb == 3)
		return ;
	free_all_parsing(data);
	write(2, "Bad floor color\n", 17);
	exit(1);
}

void	free_2_player(t_mlx_data *data)
{
	free_all_parsing(data);
	write(2, "2 player", 8);
	exit(1);
}
