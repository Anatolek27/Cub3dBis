/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:58:48 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/01 13:07:07 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	s;

	i = ft_strlen(dest);
	s = ft_strlen(src);
	j = 0;
	if (i > destsize)
		s += destsize;
	else
		s += i;
	if (destsize > i)
	{
		while (src[j] && (j + i) < destsize - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (s);
}
