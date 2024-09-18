/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:47:19 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/16 17:05:21 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3d.h"

void	cpy_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 6;
	while (data->tmp[j])
	{
		k = 0;
		while (k < get_longest_line(data->tmp))
		{
			if (data->tmp[j][k] == ' ' || !data->tmp[j][k])
				data->map.map[i][k] = '2';
			else if (data->tmp[j][k] == '2')
				data->map.map[i][k] = '3';
			else
				data->map.map[i][k] = data->tmp[j][k];
			k++;
		}
		data->map.map[i][k] = '\0';
		i++;
		j++;
	}
	data->map.map[i] = NULL;
}

int	get_map_lines(char **file, t_data *data)
{
	int	i;

	i = 6;
	while (file[i])
	{
		i++;
	}
	return (i - 6);
}

int	get_longest_line(char **file)
{
	int	i;
	int	j;
	int	c;

	i = 6;
	c = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] != '\0')
			j++;
		if (j > c)
			c = j;
		i++;
	}
	return (c);
}

void	get_map(t_data *data)
{
	int	i;
	int	j;

	data->map.map = malloc(sizeof(char *)
			* (get_map_lines(data->tmp, data) + 1));
	if (!data->map.map)
		exit(ft_exit(data, "Error: Malloc error"));
	i = get_longest_line(data->tmp);
	j = 0;
	while (j < get_map_lines(data->tmp, data))
	{
		data->map.map[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (data->map.map[j] == NULL)
		{
			while (j > 0)
				free(data->map.map[--j]);
			free(data->map.map);
			exit(ft_exit(data, "Error: Malloc error"));
		}
		j++;
	}
	data->map.map[j] = NULL;
	cpy_map(data);
}
