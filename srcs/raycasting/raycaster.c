/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:41:49 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 02:21:22 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

int	get_color_from_texture(t_texture *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	fill_img(t_data *data, t_images *img)
{
	int	i;
	int	j;

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

t_texture	*get_texture(t_data *data)
{
	t_texture	*texture;

	if (data->r.side == 0)
	{
		if (data->r.raydirx > 0)
			texture = &data->images.so;
		else
			texture = &data->images.no;
	}
	else
	{
		if (data->r.raydiry > 0)
			texture = &data->images.ea;
		else
			texture = &data->images.we;
	}
	return (texture);
}

void	ray_cast(t_data *data, t_images *img)
{
	int			i;
	t_texture	*t;
	int			y;

	i = 0;
	while (i < 1280)
	{
		init_raycasting(data, i);
		get_ray_dist(data);
		check_hit(data);
		get_wall_dist(data);
		t = get_texture(data);
		select_texture(data, t);
		y = data->r.drawstart;
		while (y < data->r.drawend)
		{
			data->r.draw = y * 256 - 1024 * 128 + data->r.lineheight * 128;
			data->r.texy = ((data->r.draw * t->height)
					/ data->r.lineheight) / 256;
			data->r.clr = get_color_from_texture(t, data->r.texx, data->r.texy);
			my_mlx_pixel_put(img, i, y, data->r.clr);
			y++;
		}
		i++;
	}
}

int	game_loop(t_data *data)
{
	t_images	img;

	img.img = mlx_new_image(data->mlx, 1280, 1024);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.img || !img.addr)
	{
		printf("error: Image creation failed.\n");
		return (1);
	}
	fill_img(data, &img);
	ray_cast(data, &img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
	mlx_destroy_image(data->mlx, img.img);
	return (0);
}
