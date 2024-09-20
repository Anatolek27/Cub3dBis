#include "../../Cub3d.h"

void get_images(t_data *data)
{
	int w;
	int h;

	data->images.no.img = mlx_xpm_file_to_image(data->mlx, data->paths.pn, &w, &h);
	if (!data->images.no.img)
		exit (ft_exit(data, "Error: Xpm file not found"));
	data->images.no.addr = mlx_get_data_addr(data->images.no.img, &data->images.no.bits_per_pixel, &data->images.no.line_length, &data->images.no.endian);
	data->images.no.width = w;
	data->images.no.height = h;

	data->images.so.img = mlx_xpm_file_to_image(data->mlx, data->paths.ps, &w, &h);
	if (!data->images.so.img)
		exit (ft_exit(data, "Error: Xpm file not found"));
	data->images.so.addr = mlx_get_data_addr(data->images.so.img, &data->images.so.bits_per_pixel, &data->images.so.line_length, &data->images.so.endian);
	data->images.so.width = w;
	data->images.so.height = h;

	data->images.we.img = mlx_xpm_file_to_image(data->mlx, data->paths.pw, &w, &h);
	if (!data->images.we.img)
		exit (ft_exit(data, "Error: Xpm file not found"));
	data->images.we.addr = mlx_get_data_addr(data->images.we.img, &data->images.we.bits_per_pixel, &data->images.we.line_length, &data->images.we.endian);
	data->images.we.width = w;
	data->images.we.height = h;

	data->images.ea.img = mlx_xpm_file_to_image(data->mlx, data->paths.pe, &w, &h);
	if (!data->images.ea.img)
		exit (ft_exit(data, "Error: Xpm file not found"));
	data->images.ea.addr = mlx_get_data_addr(data->images.ea.img, &data->images.ea.bits_per_pixel, &data->images.ea.line_length, &data->images.ea.endian);
	data->images.ea.width = w;
	data->images.ea.height = h;
}