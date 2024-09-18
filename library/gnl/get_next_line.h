/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:20:51 by hguillau          #+#    #+#             */
/*   Updated: 2022/08/10 14:19:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlenn(char *str);
char	*get_next_line(int fd);
int		ft_search(char *str);
char	*ft_substrr(char *str, int start, int end);
void	ft_put_buf(char **docu, char *buf);
char	*ft_get_line(char **docu);

#endif
