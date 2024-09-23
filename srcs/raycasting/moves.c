/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:01:19 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 02:18:02 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	left_right(int keycode, t_data *data)
{
	double	movex;
	double	movey;

	if (keycode == 100)
	{
		movex = data->r.diry * MOVE_SPEED;
		movey = -data->r.dirx * MOVE_SPEED;
		if (data->map.map[(int)(data->r.posx + movex)]
			[(int)(data->r.posy + movey)] != '1')
			data->r.posx += movex;
		if (data->map.map[(int)(data->r.posx + movey)]
			[(int)(data->r.posy + movey)] != '1')
			data->r.posy += movey;
	}
	if (keycode == 97)
	{
		movex = -data->r.diry * MOVE_SPEED;
		movey = data->r.dirx * MOVE_SPEED;
		if (data->map.map[(int)(data->r.posx + movex)]
			[(int)(data->r.posy + movey)] != '1')
			data->r.posx += movex;
		if (data->map.map[(int)(data->r.posx + movex)]
			[(int)(data->r.posy + movey)] != '1')
			data->r.posy += movey;
	}
}

void	front_back(int keycode, t_data *data)
{
	if (keycode == 119)
	{
		if (data->map.map[(int)(data->r.posx + data->r.dirx * MOVE_SPEED)]
			[(int)(data->r.posy)] != '1')
			data->r.posx += data->r.dirx * MOVE_SPEED;
		if (data->map.map[(int)(data->r.posx)]
			[(int)(data->r.posy + data->r.diry * MOVE_SPEED)]
				!= '1')
			data->r.posy += data->r.diry * MOVE_SPEED;
	}
	if (keycode == 115)
	{
		if (data->map.map[(int)(data->r.posx
				- data->r.dirx * MOVE_SPEED)][(int)(data->r.posy)] != '1')
			data->r.posx -= data->r.dirx * MOVE_SPEED;
		if (data->map.map[(int)(data->r.posx)]
			[(int)(data->r.posy - data->r.diry * MOVE_SPEED)] != '1')
			data->r.posy -= data->r.diry * MOVE_SPEED;
	}
}

void	rotate_camera_right(t_data *data)
{
	double	opx;
	double	odx;

	odx = data->r.dirx;
	data->r.dirx = data->r.dirx * cos(-ROT_SPEED)
		- data->r.diry * sin(-ROT_SPEED);
	data->r.diry = odx * sin(-ROT_SPEED) + data->r.diry * cos(-ROT_SPEED);
	opx = data->r.planex;
	data->r.planex = data->r.planex * cos(-ROT_SPEED)
		- data->r.planey * sin(-ROT_SPEED);
	data->r.planey = opx * sin(-ROT_SPEED)
		+ data->r.planey * cos(-ROT_SPEED);
}

void	rotate_camera_left(t_data *data)
{
	double	opx;
	double	odx;

	odx = data->r.dirx;
	data->r.dirx = data->r.dirx * cos(ROT_SPEED)
		- data->r.diry * sin(ROT_SPEED);
	data->r.diry = odx * sin(ROT_SPEED) + data->r.diry * cos(ROT_SPEED);
	opx = data->r.planex;
	data->r.planex = data->r.planex * cos(ROT_SPEED)
		- data->r.planey * sin(ROT_SPEED);
	data->r.planey = opx * sin(ROT_SPEED) + data->r.planey * cos(ROT_SPEED);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data, "Game closed");
	if (keycode == 119 || keycode == 115)
		front_back(keycode, data);
	if (keycode == 100 || keycode == 97)
		left_right(keycode, data);
	if (keycode == 65361)
		rotate_camera_left(data);
	if (keycode == 65363)
		rotate_camera_right(data);
	return (0);
}
