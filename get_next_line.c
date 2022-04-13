/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:34:51 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/07 18:17:15 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				*buf;
	size_t				buffsize;
	static size_t		line = 0;

	buffsize = BUFFER_SIZE + 1;
	buf = (char *) malloc(sizeof(char *) * BUFFER_SIZE);
	if (!buf)
		return (0);
	buf = ft_readline(buf, &buffsize, &line, fd);
	if (!buffsize)
	{
		free(buf);
		return (0);
	}
	if (!ft_checknextnl(fd, line))
		return (0);
	return (ft_callocrest(buf));
}

int	main(void)
{
	int n = 3;
	while (n--)
		printf("%s", get_next_line(open("prueba.txt", O_RDONLY)));
}
