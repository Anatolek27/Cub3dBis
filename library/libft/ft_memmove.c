/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:51:31 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/07 11:40:16 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dst;
	const char	*source;

	dst = dest;
	source = src;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		while (len--)
			*dst++ = *source++;
	}
	else
	{
		source += len;
		dst += len;
		while (len--)
			*--dst = *--source;
	}
	return (dest);
}
