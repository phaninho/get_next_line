/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/23 18:54:14 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_mem(char **str)
{
	if (*str)
		ft_strdel(str);
}

static void			check_str(t_line *in, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((in->chr = ft_strchr(in->str, '\n')))
	{
		*line = ft_strsub(in->str, 0, (size_t)(in->chr - in->str));
		if (*(in->chr + 1))
			in->tmp = ft_strdup(in->chr + 1);
		else
			in->tmp = NULL;
		free_mem(&(in->str));
		in->str = in->tmp;
	}
	else
	{
		*line = in->str;
		in->str = NULL;
	}
}

static int			read_buffer(char **line, t_line *in)
{
	if (!(in->chr = ft_strchr(in->buff, '\n')))
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, in->buff);
		free_mem(&in->tmp);
		return (0);
	}
	else
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->buff, 0,
					(size_t)(in->chr - in->buff)));
		free_mem(&(in->tmp));
		if (*(in->chr + 1))
			in->str = ft_strdup(in->chr + 1);
		return (1);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_line			in;

	in.chr = NULL;
	if (!line || fd < 0 || !(in.buff = (char *)malloc(sizeof(char) *
					(BUFF_SIZE + 1))))
		return (-1);
	*line = NULL;
	if (in.str)
		check_str(&in, line);
	while (!in.chr && (in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		if (read_buffer(line, &in))
			break ;
	}
	free_mem(&in.buff);
	return (*line || in.str ? 1 : 0);
}
