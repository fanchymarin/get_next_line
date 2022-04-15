/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:34:51 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/15 18:49:16 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_returnline(char *buf)
{
	int		i;
	char	*p;
	
	i = 0;
	while (buf[i] != '\n')
		++i;
	p = (char *) malloc(sizeof(char) * i + 2);
	i = 0;
	while (buf[i] != '\n')
	{
		p[i] = buf[i];
		i++;
	}
	p[i++] = '\n';
	p[i] = 0;
	return (p);
}

char	*ft_memread(int fd, char *buf)
{
	char	*p;

	p = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(buf, '\n'))
	{
		read(fd, p, BUFFER_SIZE);
		p[BUFFER_SIZE] = 0;
		buf = ft_strjoin(buf, p);
	}
	free(p);
	return (buf);
}

char	*get_next_line(int fd)
{
	static	char	*memory = 0;
	char			*buf;
	int				read_stat;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!memory)
		memory = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!memory)
		return (0);
	if (!(*memory))
	{
		read_stat = read(fd, memory, BUFFER_SIZE);
		if (read_stat <= 0)
			return (0);
		memory[BUFFER_SIZE] = 0;
	}
	buf = ft_memread(fd, memory);
	memory = ft_strchr(buf, '\n') + 1;
	return (ft_returnline(buf));
}
/*
int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);

	return (0);
}*/
