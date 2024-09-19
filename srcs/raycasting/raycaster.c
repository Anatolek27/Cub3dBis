#include "../../Cub3d.h"

int game_loop(t_data *data)
{
    int i;
    t_images img;

    // Crée une nouvelle image pour cette frame
    img.img = mlx_new_image(data->mlx, 1280, 1024);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    if (!img.img || !img.addr)
    {
        printf("Error: Image creation failed.\n");
        return (1); // Gère l'erreur si l'image ne peut être créée
    }

    i = 0;
    while (i < 1280)
    {
        double cameraX = 2.0 * i / 1280.0 - 1.0; // Calcul correct du ratio
        double rayDirX = data->r.dirX + data->r.planeX * cameraX;
        double rayDirY = data->r.dirY + data->r.planeY * cameraX;

        int mapX = (int)data->r.posX;
        int mapY = (int)data->r.posY;

        double sideDistX;
        double sideDistY;

        // Utilisation de fabs pour éviter les divisions par zéro
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        // Calcul des pas et des premières distances à parcourir
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->r.posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->r.posX) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->r.posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->r.posY) * deltaDistY;
        }

        // Algorithme DDA (Digital Differential Analyzer)
        while (hit == 0)
        {
            // Avance dans la direction la plus proche
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            // Vérifie si un mur est touché
            if (data->map.map[mapX][mapY] == '1')
                hit = 1;
        }

        // Calcul de la distance perpendiculaire au mur
        if (side == 0)
            perpWallDist = (mapX - data->r.posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - data->r.posY + (1 - stepY) / 2) / rayDirY;

        // Calcul de la hauteur de la ligne à dessiner
        int lineHeight = (int)(1024 / perpWallDist);

        // Calcul des positions de début et de fin pour dessiner la ligne
        int drawStart = -lineHeight / 2 + 1024 / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + 1024 / 2;
        if (drawEnd >= 1024)
            drawEnd = 1023;

        // Choisir une couleur pour le mur selon le côté (par exemple, rouge et vert)
        int color = (side == 1) ? data->t.rgbc_hex : 0xFF0000; // Couleur en fonction du côté du mur

        // Dessiner la ligne pour cette colonne (de drawStart à drawEnd)
        for (int y = drawStart; y < drawEnd; y++)
        {
            my_mlx_pixel_put(&img, i, y, color); // Remplir chaque colonne avec la couleur choisie
        }

        i++;
    }

    // Affiche l'image dans la fenêtre
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);

    // Détruis l'image pour éviter les fuites de mémoire
    mlx_destroy_image(data->mlx, img.img);

    return (0);
}
