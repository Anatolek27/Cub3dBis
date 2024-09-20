#include "../../Cub3d.h"

void get_images(t_data *data)
{
	int w;
	int h;

	data->images.no = mlx_xpm_file_to_image(data->mlx, data->paths.pn, &w, &h);
	if (!data->images.no)
		exit(ft_exit(data, "Error: xpm not found"));
	data->images.so = mlx_xpm_file_to_image(data->mlx, data->paths.ps, &w, &h);
	if (!data->images.so)
		exit(ft_exit(data, "Error: xpm not found"));
	data->images.we = mlx_xpm_file_to_image(data->mlx, data->paths.pw, &w, &h);
	if (!data->images.we)
		exit(ft_exit(data, "Error: xpm not found"));
	data->images.ea = mlx_xpm_file_to_image(data->mlx, data->paths.pe, &w, &h);
	if (!data->images.ea)
		exit(ft_exit(data, "Error: xpm not found"));
}
