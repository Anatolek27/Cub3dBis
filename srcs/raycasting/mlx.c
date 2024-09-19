#include "../../Cub3d.h"

void my_mlx_pixel_put(t_images *img, int x, int y, int rgb)
{
    if (x >= 0 && x < 1280 && y >= 0 && y < 1024)
    {
        char *dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)dst = rgb;
    }
}
int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(ft_exit(data, "Game closed"));
	return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)  // Touche ESC (code pour Linux)
        ft_exit(data, "Game closed");

    if (keycode == 119)  // Touche W (code Linux)
    {
        if (data->map.map[(int)(data->r.posX + data->r.dirX * MOVE_SPEED)][(int)(data->r.posY)] != '1')
            data->r.posX += data->r.dirX * MOVE_SPEED;
        if (data->map.map[(int)(data->r.posX)][(int)(data->r.posY + data->r.dirY * MOVE_SPEED)] != '1')
            data->r.posY += data->r.dirY * MOVE_SPEED;
    }

    if (keycode == 115)  // Touche S (code Linux)
    {
        if (data->map.map[(int)(data->r.posX - data->r.dirX * MOVE_SPEED)][(int)(data->r.posY)] != '1')
            data->r.posX -= data->r.dirX * MOVE_SPEED;
        if (data->map.map[(int)(data->r.posX)][(int)(data->r.posY - data->r.dirY * MOVE_SPEED)] != '1')
            data->r.posY -= data->r.dirY * MOVE_SPEED;
    }

    if (keycode == 100)  // A
    {
        double moveX = data->r.dirY * MOVE_SPEED;
        double moveY = -data->r.dirX * MOVE_SPEED;
        if (data->map.map[(int)(data->r.posX + moveX)][(int)(data->r.posY + moveY)] != '1')
            data->r.posX += moveX;
        if (data->map.map[(int)(data->r.posX + moveX)][(int)(data->r.posY + moveY)] != '1')
            data->r.posY += moveY;
    }

    if (keycode == 97)  // D
    {
        double moveX = -data->r.dirY * MOVE_SPEED;
        double moveY = data->r.dirX * MOVE_SPEED;
        if (data->map.map[(int)(data->r.posX + moveX)][(int)(data->r.posY + moveY)] != '1')
            data->r.posX += moveX;
        if (data->map.map[(int)(data->r.posX + moveX)][(int)(data->r.posY + moveY)] != '1')
            data->r.posY += moveY;
    }

    if (keycode == 65361)  // Touche A (code Linux)
    {
        double oldDirX = data->r.dirX;
        data->r.dirX = data->r.dirX * cos(ROT_SPEED) - data->r.dirY * sin(ROT_SPEED);
        data->r.dirY = oldDirX * sin(ROT_SPEED) + data->r.dirY * cos(ROT_SPEED);
        double oldPlaneX = data->r.planeX;
        data->r.planeX = data->r.planeX * cos(ROT_SPEED) - data->r.planeY * sin(ROT_SPEED);
        data->r.planeY = oldPlaneX * sin(ROT_SPEED) + data->r.planeY * cos(ROT_SPEED);
    }

    if (keycode == 65363)  // Touche D (code Linux)
    {
        double oldDirX = data->r.dirX;
        data->r.dirX = data->r.dirX * cos(-ROT_SPEED) - data->r.dirY * sin(-ROT_SPEED);
        data->r.dirY = oldDirX * sin(-ROT_SPEED) + data->r.dirY * cos(-ROT_SPEED);
        double oldPlaneX = data->r.planeX;
        data->r.planeX = data->r.planeX * cos(-ROT_SPEED) - data->r.planeY * sin(-ROT_SPEED);
        data->r.planeY = oldPlaneX * sin(-ROT_SPEED) + data->r.planeY * cos(-ROT_SPEED);
    }
    return (0);
}

void init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->r.dirX = -1;
	data->r.dirY = 0;
	data->r.planeX = -0.66;
	data->r.planeY = 0;
	data->r.fov = 0.66;
}

void start_mlx(t_data *data)
{
    // Initialisation de MLX
	get_images(data);
	init_mlx(data);
    data->mlx_win = mlx_new_window(data->mlx, 1280, 1024, "Cub3d");
    mlx_hook(data->mlx_win, 17, 0, ft_close, data);
    mlx_hook(data->mlx_win, 2, 1L<<0, handle_keypress, data);
    mlx_loop_hook(data->mlx, game_loop, data);

    // Boucle MLX
    mlx_loop(data->mlx);
}
