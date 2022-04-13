/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:53:49 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/07 18:14:55 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_callocrest(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		++i;
	while (++i <= BUFFER_SIZE)
		str[i] = 0;
	return (str);
}

char	*ft_readline(char *buf, size_t *buffsize, size_t *line, int fd)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (--(*buffsize))
	{
		read(fd, &buf[i++], 1);
		if (buf[i - 1] == '\n')
		{
			if (i2 == *line)
			{
				(*line)++;
				break ;
			}
			else
			{
				*buffsize = BUFFER_SIZE + 1;
				i = 0;
				i2++;
			}
		}
	}
	return (buf);
}

int	ft_checknextnl(int fd, size_t line)
{
	char	*buf;
	size_t	buffsize;

	buf = (char *) malloc(sizeof(char *));
	buffsize = BUFFER_SIZE + 1;
	while(--buffsize)
	{
		read(fd, buf, 1);
		if (*buf == '\n')
			--line;
	}
	free(buf);
	if (!line)
		return (0);
	return (1);
}
