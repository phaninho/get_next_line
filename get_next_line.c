/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/01 22:51:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnlinc.h"

int			get_next_line(int fd, char **line)
{
	char	*buff;
	read_line(fd, line);
	*line = NULL;

}

void		read_file(int fd, char **line)
{
	int		oct;
	char	*str;
	char	*tmp;

	str = NULL;
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
		if (oct == -1)
			return (NULL);
		line = ft_strchr(buff, '\n');
		if (!str)
			str = ft_strdup(buff);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buff);
			free(tmp);
		}
	}
}

//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
