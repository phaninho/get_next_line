/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/16 16:58:33 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		find_bsn(t_line *in, char **line)
{
	in->ret = 0;
	in->chr = NULL;
	/*if (in->str && (in->chr = ft_strchr(in->str, '\n')))
	{
		printf("goooooooooooooo");
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->str, 0,
					(size_t)(in->chr - in->str)));
		if (in->tmp)
			ft_strdel(&in->tmp);
		ft_strdel(&in->str);
		in->str = ft_strdup(in->str + 1);
		in->ret = 1;
	}*/
	if (!in->ret && (in->chr = ft_strchr(in->buff, '\n')))
	{
		printf("goooooooooooooooooooooo");
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->buff, 0, (size_t)(in->chr - in->buff)));
		if (in->tmp)
			ft_strdel(&in->tmp);
		if (in->str)
			ft_strdel(&in->str);
		in->str = ft_strdup(in->chr + 1);
		in->ret = 1;
	}
}

int			check_str(t_line in, char *line)
{
	in.chr = NULL;
	printf("entre str: %s\n", in.str);
	if ((in.chr = ft_strchr(in.str, '\n')))
	{
		printf("regarde\n");
		in.tmp = line;
		line = ft_strjoin(line, ft_strsub(in.str, 0, ((size_t)(in.chr - in.str)
		== 0 ? 1 : (size_t)(in.chr - in.str))));
		if (in.tmp)
			ft_strdel(&in.tmp);
		if ((in.chr + 1))
			in.str = ft_strdup(in.chr + 1);
		printf("pouk str: %s\n", in.str);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_line			in;
	printf("stattttiiiiiiiiiiiiic%s\n", in.str);
	in.ret = 0;
	if (*line)
		ft_strdel(line); // met line a NULL dans le retour
	if (in.str && (check_str(in, *line) == 1))
		return (1);
	if (*line)
		ft_strdel(line);
	if (!(in.buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		printf("buff : %s\n",in.buff);
		if (!(ft_strchr(in.buff, '\n')))
		{
			if (in.str)
			{
				printf("paffffffffff str: %s\n", in.str);
				*line = ft_strjoin(in.str, in.buff);
				ft_strdel(&in.str);
			}
			else
			{
				in.tmp = *line;
				*line = ft_strjoin(*line, in.buff);
				if (in.tmp)
					ft_strdel(&in.tmp);
			}
			printf("-------------------------line: %s\n", *line);
		}
		else
			find_bsn(&in, line);
		if (in.ret == 1)
			return (1);
	}
	if (in.buff)
		ft_strdel(&in.buff);
	if (!(in.oct && in.str))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int i = 0;
	int fd;
	char	*line;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while (i++ < 15)
	{
		(get_next_line(fd, &line) == -1) ? ft_putstr("error\n") : printf("-#%s#-\n", line);
	}
	return (0);
}

