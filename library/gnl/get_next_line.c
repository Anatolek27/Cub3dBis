/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:21:06 by hguillau          #+#    #+#             */
/*   Updated: 2022/07/12 09:36:22 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*docu;
	char		buf[BUFFER_SIZE + 1];
	int			size;

	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		ft_put_buf(&docu, buf);
		if (ft_search(docu) != -1)
			return (ft_get_line(&docu));
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_get_line(&docu));
}
