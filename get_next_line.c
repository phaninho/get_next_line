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

char		*join_next_line(char *str, char **line, char *chr)
{
	char	*tmp;

	tmp = NULL;
	chr = NULL;
	if ((chr = ft_strchr(str, '\n')) && str)
	{
		tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(str, 0, (size_t)(chr - str)));
		if (tmp)
			free(tmp);
	}
	else
		if (str)
			return (str);
	return (*line);
}

int			get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	char			*buff;
	char			*tmp;
	int				oct;
	char			*chr;

	*line = NULL;
	chr = NULL;
	tmp = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (str)
	{
		*line = join_next_line(str, line, chr);
		if ((chr = ft_strchr(str, '\n')))
		{
			str = ft_strdup(chr + 1);
			return (0);
		}
	}
		while ((oct = read(fd, buff, BUFF_SIZE)))
		{
			buff[oct] = '\0';
			if (oct == -1)
				return (-1);
			if ((chr = ft_strchr(buff, '\n')))
			{
				tmp = *line;
				*line = ft_strjoin(*line, ft_strsub(buff, 0,
				(size_t)(chr - buff)));
				str = ft_strdup(chr + 1);
				if (tmp)
					free(tmp);
				return (0);
			}
			else
			{
				tmp = *line;
				*line = ft_strjoin(*line, buff);
			}
			if (tmp)
				free(tmp);
		}
	return (0);
}

int		main(int ac, char **av)
{
	int		i = 0;
	int		fd;
	char	*line;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while (i++ < 8)
	{
		(get_next_line(fd, &line) == -1) ? ft_putstr("error\n") : printf("--final line : %s\n", line);
	}
	if (line)
	free(line);
	return (0);
}
//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
