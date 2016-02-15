/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/15 15:46:00 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		find_bsn(t_line *in, char **line)
{
	in->ret = 0;
	in->chr = NULL;
	in->chr = ft_strchr(in->buff, '\n');
	if (((size_t)(in->chr)) - ((size_t)(in->buff)))
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->buff, 0,
					(size_t)(in->chr - in->buff)));
		ft_strdel(&in->tmp);
		if ((in->chr + 1))
		{
			if (in->str)
				ft_strdel(&in->str);
			in->str = ft_strdup(in->chr + 1);
		}
			else
			in->ret = 1;
	}
}

int			check_str(t_line in, char *line)
{
	in.chr = NULL;
	if ((in.chr = ft_strchr(in.str, '\n')))
	{
		in.tmp = line;
		line = ft_strjoin(line, ft_strsub(in.str, 0, (size_t)(in.chr - in.str)));
		if (in.tmp)
			ft_strdel(&in.tmp);
		if (in.chr + 1)
		{
			if (in.str)
				ft_strdel(&in.str);
			if (in.buff)
				ft_strdel(&in.buff);
			in.str = ft_strdup(in.chr + 1);
		}
		printf("pouk\n");
		return (1);
	}
	printf("poukpouko\n");
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_line			in;

	if ((check_str(in, *line) == 1))
		return (1);
	if (!(in.buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		printf("oct = %d buff : %s\n", in.oct, in.buff);
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		if (!(ft_strchr(in.buff, '\n')))
		{
			in.tmp = in.str;
			in.str = ft_strjoin(in.str, in.buff);
			ft_strdel(&in.buff);
			if (in.tmp)
				ft_strdel(&in.tmp);
			printf("le str :%s\n", in.str);
		}
		else
		{
			printf("bim\n");
			find_bsn(&in, line);
		}
		if (in.buff)
			ft_strdel(&in.buff);
		if (in.ret == 1)
			return (1);
	}
	if (!(in.oct) && !in.str)
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
