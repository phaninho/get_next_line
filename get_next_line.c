/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/11 16:11:59 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char		*join_next_line(char *str, char **line, char *chr)
{
	char	*tmp;

	tmp = NULL;
	if ((chr = ft_strchr(str, '\n')) && str)
	{
		tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(str, 0, (size_t)(chr - str)));
		if (str)
			ft_strdel(&str);
		if (tmp)
			ft_strdel(&tmp);
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
	int				out = 0;
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
			if ((chr + 1))
				str = ft_strdup(chr + 1);
			if (buff)
				ft_strdel(&buff);
		printf("return 1-0\n");
			return(1);
		}
	}
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
		if (oct < BUFF_SIZE)
			out++;
		printf("oct: %d\n", oct);
		buff[oct] = '\0';
		if (oct == -1)
			return (-1);
		if (buff[0] == '\n' && oct)
		{
			str = ft_strdup(buff + 1);
			if (buff)
				ft_strdel(&buff);
			if (out && !str)
			{
				printf("return 0-mid str: %s\n", str);
				return (0);
			}
			if (str)
			{
				printf("return 1-mid str: %s\n", str);
				return (1);
			}
		}
		if ((chr = ft_strchr(buff, '\n')) && oct)
		{
			tmp = *line;
			*line = ft_strjoin(*line, ft_strsub(buff, 0,
			(size_t)(chr - buff)));
			str = ft_strdup(chr + 1);
			if (tmp)
				ft_strdel(&tmp);
			if (buff)
				ft_strdel(&buff);
			if (out && !str)
			{
			printf("return 0-end str: %s\n", str);
				return (0);
			
			}
				if (str)
				{
			printf("return 1-end str: %s\n", str);
					return (1);
				}
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buff);
			if (tmp)
				ft_strdel(&tmp);
		}
		if (!oct && !str)
		{
			printf("return 0 final\n");
			return(0);
		}
	}
	printf("return 0-1\n");
	return (0);
}

int		main(int ac, char **av)
{
	int		i = 0;
	int		fd;
	char	*line;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while (i++ < 15)
	{
		(get_next_line(fd, &line) == -1) ? ft_putstr("error\n") : printf("-##- : %s\n", line);
	}
	if (line)
		ft_strdel(&line);
	return (0);
}
