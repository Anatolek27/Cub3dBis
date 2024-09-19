#include "../../Cub3d.h"

void get_images(t_data *data)
{
	int w;
	int h;
	void *img;
	printf("%s\n%s\n%s\n%s\n", data->paths.pn, data->paths.ps, data->paths.pe, data->paths.pw);
	img = mlx_xpm_file_to_image(data->mlx, data->paths.pn, &w, &h);
	if (!img)
		exit(ft_exit(data, "Error: xpm not found"));
}
