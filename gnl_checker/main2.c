/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:19:31 by rabougue          #+#    #+#             */
/*   Updated: 2016/03/25 14:06:40 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>

int	open_file(char *file)
{
	int		fd;
	int		j;
	char	*line;

	j = 1;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("impossible d'ouvrir le fichier!");
		return (-1);
	}
	while ((get_next_line(42, &line)) == j)
		ft_putendl(line);
	if (j == -1)
		ft_putendl("Erreur de lecture");
	ft_putstr("retour de get_next_line = ");
	ft_putnbr(get_next_line(42, &line));
	return (fd);
}

int	main(int ac, char **av)
{
	char	*line;
	int j = 1;

	if (ac == 1)
		while ((get_next_line(0, &line)) == j)
			ft_putendl(line);
	else if (ac == 2)
		open_file(av[1]);
	return (0);
}
