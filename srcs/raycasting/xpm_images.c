#include "../../Cub3d.h"

void get_images(t_data *data)
{
	int fd;
	int w;
	int h;
	
	printf("%s\n%s\n%s\n%s\n", data->paths.pn, data->paths.ps, data->paths.pe, data->paths.pw);
	data->images.no = mlx_xpm_file_to_image(data->mlx, data->paths.pn, &h, &w);
	if (!data->images.no)
		exit(ft_exit(data, "Error: Xpm image not found"));
	data->images.so = mlx_xpm_file_to_image(data->mlx, data->paths.ps, &h1, &w1);
	if (!data->images.so)
		exit(ft_exit(data, "Error: Xpm image not found"));
	int h2;
	int w2;
	data->images.we = mlx_xpm_file_to_image(data->mlx, data->paths.pw, &h2, &w2);
	if (!data->images.we)
		exit(ft_exit(data, "Error: Xpm image not found"));
	int h3;
	int w3;
	data->images.ea = mlx_xpm_file_to_image(data->mlx, data->paths.pe, &h3, &w3);
	if (!data->images.ea)
		exit(ft_exit(data, "Error: Xpm image not found"));
}
