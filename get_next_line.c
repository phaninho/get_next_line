/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/05 22:36:38 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnlinc.h"
#include <stdio.h>

int			get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	char			*buff;
	char			*tmp;
	int				oct;
	char			*chr;

	*line = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
		buff[oct] = '\0';
		printf("oct = %d\n", oct);
		if (oct == -1)
			return (-1);
		if ((chr = ft_strchr(buff, '\n')))
		{
			printf("bonjour\n");
			*line = ft_strjoin(*line, ft_strsub(buff, 0, (size_t)(chr - buff)));
			str = ft_strdup(chr + 1);
			return (1);
		}
		else
		{
			printf("monsieur\n");
			tmp = *line;
			*line = ft_strjoin(*line, buff);
			printf("line = %s\n", *line);
			if (tmp)
				free(tmp);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	get_next_line(fd, &line);
	printf("line : %s\n", line);
	return (0);
}
//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
