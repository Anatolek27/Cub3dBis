#include "../../Cub3d.h"

void fill_img(t_data *data, t_images *img)
{
    int i;
    int j;

    i = 0;
    while (i < 1024)
    {
        j = 0;
        while (j < 1280)
        {
            if (i < 1024 / 2)
                my_mlx_pixel_put(img, j, i, data->t.rgbc_hex);
            else
                my_mlx_pixel_put(img, j, i, data->t.rgbf_hex);
            j++;
        }
        i++;
    }
}

int game_loop(t_data *data)
{
    int i;
    t_images img;

    img.img = mlx_new_image(data->mlx, 1280, 1024);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    if (!img.img || !img.addr)
    {
        printf("Error: Image creation failed.\n");
        return (1);
    }
    fill_img(data, &img);
    i = 0;
    while (i < 1280)
    {
        data->r.cameraX = 2.0 * i / 1280.0 - 1.0;
        data->r.rayDirX = data->r.dirX + data->r.planeX * data->r.cameraX;
        data->r.rayDirY = data->r.dirY + data->r.planeY * data->r.cameraX;

        data->r.mapX = (int)data->r.posX;
        data->r.mapY = (int)data->r.posY;

        data->r.deltaDistX = (data->r.rayDirX == 0) ? 1e30 : fabs(1 / data->r.rayDirX);
        data->r.deltaDistY = (data->r.rayDirY == 0) ? 1e30 : fabs(1 / data->r.rayDirY);
        data->r.perpWallDist;

        int stepX;
        int stepY;

        data->r.hit = 0;
        data->r.side;

        if (data->r.rayDirX < 0)
        {
            stepX = -1;
            data->r.sideDistX = (data->r.posX - data->r.mapX) * data->r.deltaDistX;
        }
        else
        {
            stepX = 1;
            data->r.sideDistX = (data->r.mapX + 1.0 - data->r.posX) * data->r.deltaDistX;
        }

        if (data->r.rayDirY < 0)
        {
            stepY = -1;
            data->r.sideDistY = (data->r.posY - data->r.mapY) * data->r.deltaDistY;
        }
        else
        {
            stepY = 1;
            data->r.sideDistY = (data->r.mapY + 1.0 - data->r.posY) * data->r.deltaDistY;
        }

        while (data->r.hit == 0)
        {
            if (data->r.sideDistX < data->r.sideDistY)
            {
                data->r.sideDistX += data->r.deltaDistX;
                data->r.mapX += stepX;
                data->r.side = 0;
            }
            else
            {
                data->r.sideDistY += data->r.deltaDistY;
                data->r.mapY += stepY;
                data->r.side = 1;
            }
            if (data->map.map[data->r.mapX][data->r.mapY] == '1')
                data->r.hit = 1;
        }
        if (data->r.side == 0)
            data->r.perpWallDist = (data->r.mapX - data->r.posX + (1 - stepX) / 2) / data->r.rayDirX;
        else
            data->r.perpWallDist = (data->r.mapY - data->r.posY + (1 - stepY) / 2) / data->r.rayDirY;
        data->r.lineHeight = (int)(1024 / data->r.perpWallDist);
        data->r.drawStart = -data->r.lineHeight / 2 + 1024 / 2;
        if (data->r.drawStart < 0)
            data->r.drawStart = 0;
        data->r.drawEnd = data->r.lineHeight / 2 + 1024 / 2;
        if (data->r.drawEnd >= 1024)
            data->r.drawEnd = 1023;

        data->r.color = 0xFFFFFF;

        for (int y = data->r.drawStart; y < data->r.drawEnd; y++)
            my_mlx_pixel_put(&img, i, y, data->r.color);
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
    mlx_destroy_image(data->mlx, img.img);
    return (0);
}
