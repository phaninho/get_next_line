/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:52:25 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/03 16:55:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnlinc.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd;
	int	ret = 0;
	char *line;

	if (ac < 2)
		return (1);
	else
	{
		fd = open(av[1], O_RDONLY);
		ret = get_next_line(fd, &line);
	}
	return (0);
}

void		read_file(int const fd, char **line, char **buff)
{
	static unsigned int	start = 0;
	int					oct;
	char				*str;
	char				*tmp;
	char				*ret;

	str = NULL;
	while ((oct = read(fd, *buff, BUFF_SIZE)))
	{
		printf ("pouf\n");
		if (oct == -1)
			return ;
		printf("paff\n");
		if ((ret = ft_strchr(*buff, '\n')))
		{
			*line = ft_strsub(*buff, start, (size_t)(ret - *buff));
			start += (unsigned int)((ret - *buff) + 1);
		}
		printf("quand\n");
		if (!str)
			str = ft_strdup(*line);
		else
		{
		printf("tin\n");
			tmp = str;
			str = ft_strjoin(str, *line);
			free(tmp);
		}
	}
}
int			get_next_line(int const fd, char **line)
{
	char	*buff;
	read_file(fd, line, &buff);
	*line = NULL;
	return (0);
}


//ft_strjoin
//ft_strsub
//ft_strdup
//ft_strchr
