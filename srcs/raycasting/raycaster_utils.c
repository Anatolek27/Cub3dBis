/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:54:13 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 02:20:08 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	init_raycasting(t_data *data, int i)
{
	data->r.camerax = 2.0 * i / 1280.0 - 1.0;
	data->r.raydirx = data->r.dirx + data->r.planex * data->r.camerax;
	data->r.raydiry = data->r.diry + data->r.planey * data->r.camerax;
	data->r.mapx = (int)data->r.posx;
	data->r.mapy = (int)data->r.posy;
	if (data->r.raydirx == 0)
		data->r.deltadistx = 1e30;
	else
		data->r.deltadistx = fabs(1 / data->r.raydirx);
	if (data->r.raydiry == 0)
		data->r.deltadisty = 1e30;
	else
		data->r.deltadisty = fabs(1 / data->r.raydiry);
	data->r.stepx;
	data->r.stepy;
	data->r.hit = 0;
}

void	get_ray_dist(t_data *data)
{
	if (data->r.raydirx < 0)
	{
		data->r.stepx = -1;
		data->r.sidedistx = (data->r.posx - data->r.mapx)
			* data->r.deltadistx;
	}
	else
	{
		data->r.stepx = 1;
		data->r.sidedistx = (data->r.mapx + 1.0 - data->r.posx)
			* data->r.deltadistx;
	}
	if (data->r.raydiry < 0)
	{
		data->r.stepy = -1;
		data->r.sidedisty = (data->r.posy - data->r.mapy)
			* data->r.deltadisty;
	}
	else
	{
		data->r.stepy = 1;
		data->r.sidedisty = (data->r.mapy + 1.0 - data->r.posy)
			* data->r.deltadisty;
	}
}

void	check_hit(t_data *data)
{
	while (data->r.hit == 0)
	{
		if (data->r.sidedistx < data->r.sidedisty)
		{
			data->r.sidedistx += data->r.deltadistx;
			data->r.mapx += data->r.stepx;
			data->r.side = 0;
		}
		else
		{
			data->r.sidedisty += data->r.deltadisty;
			data->r.mapy += data->r.stepy;
			data->r.side = 1;
		}
		if (data->map.map[data->r.mapx][data->r.mapy] == '1')
			data->r.hit = 1;
	}
}

void	get_wall_dist(t_data *data)
{
	if (data->r.side == 0)
		data->r.perpwalldist = (data->r.mapx - data->r.posx
				+ (1 - data->r.stepx) / 2) / data->r.raydirx;
	else
		data->r.perpwalldist = (data->r.mapy - data->r.posy
				+ (1 - data->r.stepy) / 2) / data->r.raydiry;
	data->r.lineheight = (int)(1024 / data->r.perpwalldist);
	data->r.drawstart = -data->r.lineheight / 2 + 1024 / 2;
	if (data->r.drawstart < 0)
		data->r.drawstart = 0;
	data->r.drawend = data->r.lineheight / 2 + 1024 / 2;
	if (data->r.drawend >= 1024)
		data->r.drawend = 1023;
}

void	select_texture(t_data *data, t_texture *texture)
{
	if (data->r.side == 0)
		data->r.wallx = data->r.posy + data->r.perpwalldist * data->r.raydiry;
	else
		data->r.wallx = data->r.posx + data->r.perpwalldist * data->r.raydirx;
	data->r.wallx -= floor(data->r.wallx);
	data->r.texx = (int)(data->r.wallx * (double)(texture->width));
	if (data->r.side == 0 && data->r.raydirx > 0)
		data->r.texx = texture->width - data->r.texx - 1;
	if (data->r.side == 1 && data->r.raydiry < 0)
		data->r.texx = texture->width - data->r.texx - 1;
}
