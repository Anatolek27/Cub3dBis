#include "../../Cub3d.h"

void my_mlx_pixel_put(t_images *img, int x, int y, int rgb)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = rgb;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(ft_exit(data, "Game closed"));
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307) // Touche ESC sur macOS
		ft_close(data);
	return (0);
}

void start_mlx(t_data *data)
{
	t_images img;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1280, 1024, "Cub3d"); 
	img.img = mlx_new_image(data->mlx, 1280, 1024);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);

	// Capture de la fermeture de la fenêtre
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);

	// Capture de la touche ESC
	mlx_hook(data->mlx_win, 2, 1L<<0, handle_keypress, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}