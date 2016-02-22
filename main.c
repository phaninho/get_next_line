#include "get_next_line.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while ((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		//(get_next_line(fd, &line) == -1) ?
		//	ft_putstr("error\n") : printf("%s\n", line);
	}
	if (line)
		printf("%s", line);
	return (0);
}
