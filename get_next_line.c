/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/09 14:25:16 by stmartin         ###   ########.fr       */
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

	*line = NULL;
	chr = NULL;
	tmp = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
//	printf("@@@@@@@@@@@str : %s\n", str);
	if (str)
	{
		*line = join_next_line(str, line, chr);
//		printf("IIIIIIIIIIIline : %s\n", *line);
		if ((chr = ft_strchr(str, '\n')))
		{
			if ((chr + 1))
				str = ft_strdup(chr + 1);
		if (buff)
				ft_strdel(&buff);
			return (0);
		}
//			printf("=========str = %s\n@@@@@@@@line : %s\n", str, *line);
	}
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
//	printf("bing1 buff : %s\nline %s\nstr : %s\n", buff, *line, str);
		buff[oct] = '\0';
		if (oct == -1)
			return (-1);
		if (buff[0] == '\n')
		{
//			printf("èèèèèèèèèèline : %s\n àààààààààààstr : %s\n", *line, str);
			str = ft_strdup(buff + 1);
//			printf("ssssssssssssssstr : %s\n", str);
			if (buff)
				free(buff);
			return (0);
		}
		if ((chr = ft_strchr(buff, '\n')))
		{
			tmp = *line;
			*line = ft_strjoin(*line, ft_strsub(buff, 0,
			(size_t)(chr - buff)));
			str = ft_strdup(chr + 1);
//			printf("__________str : %s\n", str);
			if (tmp)
				ft_strdel(&tmp);
			if (buff)
				ft_strdel(&buff);
			return (0);
		}
		else
		{
			tmp = *line;
//	printf("bbbbbbbbbuff : %s\n #######line : %s\n", buff, *line);
			*line = ft_strjoin(*line, buff);
//	printf("lllllllllllline : %s\nttttttttttmp : %s\n", *line, tmp);
			if (tmp)
				ft_strdel(&tmp);
		}
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
	while (i++ < 15)
	{
		(get_next_line(fd, &line) == -1) ? ft_putstr("error\n") : printf("-##- : %s\n", line);
	}
	if (line)
		free(line);
	return (0);
}
//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
