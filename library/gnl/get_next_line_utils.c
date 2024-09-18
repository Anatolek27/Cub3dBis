/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:21:21 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/19 19:03:03 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substrr(char *str, int start, int end)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	if (start > end)
		return (NULL);
	res = malloc((end - start) + 2);
	i = 0;
	while (i + start <= end)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_search(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_put_buf(char **docu, char *buf)
{
	char	*zoui;
	int		i;
	int		j;

	if (!*docu)
		*docu = ft_substrr("", 0, 0);
	zoui = malloc((ft_strlenn(*docu) + ft_strlenn(buf) + 1) * sizeof(char));
	i = 0;
	while ((*docu)[i])
	{
		zoui[i] = (*docu)[i];
		i++;
	}
	j = 0;
	while (buf[j])
		zoui[i++] = buf[j++];
	zoui[i] = '\0';
	free(*docu);
	*docu = zoui;
}

char	*ft_get_line(char **docu)
{
	char	*res;
	char	*zoui;
	int		pos;

	if (!*docu)
		return (NULL);
	pos = ft_search(*docu);
	if (pos == -1)
		pos = ft_strlenn(*docu) - 1;
	res = ft_substrr(*docu, 0, pos);
	zoui = ft_substrr(*docu, pos + 1, ft_strlenn(*docu) - 1);
	free(*docu);
	*docu = zoui;
	return (res);
}
