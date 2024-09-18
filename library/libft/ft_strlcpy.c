/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:41:09 by hguillau          #+#    #+#             */
/*   Updated: 2022/03/30 15:58:36 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	char	*source;

	i = 0;
	source = (char *)src;
	if (destsize > 0)
	{
		while (source[i] && i < destsize - 1)
		{
			dest[i] = source[i];
			i++;
		}
	}
	if (destsize != 0)
		dest[i] = '\0';
	return (ft_strlen(source));
}
