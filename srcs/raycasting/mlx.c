/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:41:49 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 02:17:33 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	my_mlx_pixel_put(t_images *img, int x, int y, int rgb)
{
	char	*dst;

	if (x >= 0 && x < 1280 && y >= 0 && y < 1024)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = rgb;
	}
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(ft_exit(data, "Game closed"));
	return (0);
}

void	find_start_dir(t_data *data)
{
	if (data->p.dir == 'E')
	{
		data->r.dirx = 0;
		data->r.diry = 1;
		data->r.planex = 0.66;
		data->r.planey = 0;
	}
	else if (data->p.dir == 'W')
	{
		data->r.dirx = 0;
		data->r.diry = -1;
		data->r.planex = -0.66;
		data->r.planey = 0;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->p.dir == 'N')
	{
		data->r.dirx = -1;
		data->r.diry = 0;
		data->r.planex = 0;
		data->r.planey = 0.66;
	}
	else if (data->p.dir == 'S')
	{
		data->r.dirx = 1;
		data->r.diry = 0;
		data->r.planex = 0;
		data->r.planey = -0.66;
	}
	else
		find_start_dir(data);
	data->r.fov = 0.66;
}

void	start_mlx(t_data *data)
{
	init_mlx(data);
	get_images(data);
	data->mlx_win = mlx_new_window(data->mlx, 1280, 1024, "Cub3d");
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}
