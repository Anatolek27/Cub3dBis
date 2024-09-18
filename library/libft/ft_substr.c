/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:31 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/06 09:50:30 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	size_t			zoui;

	if (!s)
		return (NULL);
	zoui = 0;
	if (start < ft_strlen(s))
		zoui = ft_strlen(s) - start;
	if (zoui > len)
		zoui = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	res = malloc((zoui + 1) * sizeof (char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
