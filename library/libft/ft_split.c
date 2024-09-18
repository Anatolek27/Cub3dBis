/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:39:24 by hguillau          #+#    #+#             */
/*   Updated: 2022/04/06 11:00:30 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	ft_count_word(char const *s, char c)
{
	size_t	i;
	int		nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{	
		if ((ft_check_sep(s[i], c) == 0)
			&& (ft_check_sep(s[i + 1], c) == 1))
			nb_word++;
		i++;
	}
	return (nb_word);
}

static int	ft_free_tab(char **split, size_t pos)
{
	size_t	i;

	i = 0;
	while (split[i] && i < pos)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (-1);
}

static int	ft_print_tab(char **split, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	while (s[start])
	{
		if (s[start] == c)
			start++;
		else
		{
			end = 0;
			while (ft_check_sep(s[start + end], c) == 0)
				end++;
			split[i] = ft_substr(s, start, end);
			if (!split[i])
				return (ft_free_tab(split, i));
			start += end;
			i++;
		}
	}
	split[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	nb_word;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	split = malloc((nb_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (ft_print_tab(split, s, c) < 0)
		return (NULL);
	if (split[nb_word] != 0)
		return (NULL);
	return (split);
}
