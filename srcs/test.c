e2 = 2 * mlx_data->bres_val.err;
	while (mlx_data->bres_val.x1 <= mlx_data->bres_val.x2
	|| mlx_data->bres_val.y1 <= mlx_data->bres_val.y2)
	{
		if (mlx_data->bres_val.x1 == mlx_data->bres_val.x2
			&& mlx_data->bres_val.y1 == mlx_data->bres_val.y2)
			break ;
		e2 = 2 * mlx_data->bres_val.err;
		my_mlx_pixel_put(&mlx_data->img, mlx_data->bres_val.x1,
			mlx_data->bres_val.y1, color);
		if (e2 > -mlx_data->bres_val.dy)
		{
			mlx_data->bres_val.err -= mlx_data->bres_val.dy;
			mlx_data->bres_val.x1++;
		}
		else
		{
			mlx_data->bres_val.err += mlx_data->bres_val.dx;
			mlx_data->bres_val.y1++;
		}
	}