/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/02 18:53:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnlinc.h"

void		read_file(int fd, char *line, char **buff)
{
	static int	len = 0;
	int			oct;
	char		*str;
	char		*tmp;
	char		*ret;

	str = NULL;
	while ((oct = read(fd, buff, BUFF_SIZE)))
	{
		if (oct == -1)
			return ;
		ret = ft_strchr(*buff, '\n');
		line = ft_strsub(*buff, len, (ret - *buff));
		len += (int)((ret - *buff) + 1);
		if (!str)
			str = ft_strdup(line);
		else
		{
			tmp = str;
			str = ft_strjoin(str, *buff);
			free(tmp);
		}
	}
}
int			get_next_line(int const fd, char **line)
{
	char	*buff;
	read_file(fd, *line, &buff);
	*line = NULL;
	return (0);
}


//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
