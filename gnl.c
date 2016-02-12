/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:24:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/12 16:11:20 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		find_bsn(t_line *in, char **line)
{
	in->ret = 0;
	in->chr = ft_strchr(in->buff, '\n');
	if (((size_t)(in->chr)) - ((size_t)(in->buff)))
	{
		in->tmp = *line;
		*line = ft_strjoin(*line, ft_strsub(in->buff, 0,
					(size_t)(in->chr - in->buff)));
		ft_strdel(&in->tmp);
		if ((in->chr + 1))
			in->str = ft_strdup(in->chr + 1);
		else
			in->ret = 1;
	}
}

int			get_next_line(int const fd, char **line)
{
	t_line			in;

	if (!(in.buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((in.oct = read(fd, in.buff, BUFF_SIZE)))
	{
		if (in.oct == -1)
			return (-1);
		in.buff[in.oct] = '\0';
		if (!in.str && (ft_strchr(in.buff, '\n')))
			find_bsn(&in, line);
		else if ((ft_strlen(in.buff)))
		{
			in.str = ft_strdup(in.buff);
			ft_strdel(&in.buff);
			return (1);
		}
		if (in.ret == 1)
			return (1);
	}
	if (!(in.oct) && !in.str)
		return (0);
	return (1);
}
