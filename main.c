#include "get_next_line.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		ret;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (-1);
	while ((ret = (get_next_line(fd, &line))) > 0)
	{
		printf("[%d] : %s\n", ret, line);
		//(get_next_line(fd, &line) == -1) ?
		//	ft_putstr("error\n") : printf("%s\n", line);
	}
	printf("[%d] : %s\n", ret, line);
	return (0);
}
