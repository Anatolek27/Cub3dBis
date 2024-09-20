/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:56:24 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:11 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	check_file_name(t_data *data)
{
	int	i;

	i = ft_strlen(data->paths.pfile) - 1;
	if (data->paths.pfile[i] != 'b' || data->paths.pfile[i - 1] != 'u'
		|| data->paths.pfile[i - 2] != 'c' || data->paths.pfile[i - 3] != '.')
		exit (ft_exit(data, "Error: Map doesn't have .cub extension"));
	data->fd = open(data->paths.pfile, O_RDONLY);
	if (data->fd < 0)
		exit (ft_exit(data, "Error: Doesn't exist"));
	close(data->fd);
	if (get_line_nb(data) == 0)
		exit(ft_exit(data, "Error: File is empty"));
	data->file = ft_calloc(get_line_nb(data) + 1, sizeof(char *));
	if (!data->file)
		exit (ft_exit(data, "Error: Malloc error"));
}

void	parsing(t_data *data)
{
	int	i;

	check_file_name(data);
	data->fd = open(data->paths.pfile, O_RDONLY);
	get_file(data);
	close (data->fd);
	get_clean_file(data);
	get_paths(data);
	check_t_paths(data);
	check_rgb(data);
	get_map(data);
	data->p.x = -1;
	data->p.y = -1;
	i = 0;
	check_map_chars(data, i);
	check_map_playable(data, data->p.x, data->p.y);
	data->r.posX = data->p.x + 0.5;
	data->r.posY = data->p.y + 0.5;
}
