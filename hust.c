#include <stdio.h>
#include "../libft/libft.h"

char	*test_func(int i)
{
	static char	*test = NULL;
	if (i == 1)
		test = ft_strdup("Bonjour ");
	if (i == 2)
		test = ft_strjoin(test, "les amis !");
	if (i == 3)
		test = ft_strjoin(test, " Bonne nuit.");
	return (test);
}

int		main()
{
	int		i;

	i = 0;
	while (++i < 4)
		printf("%d : %s\n", i,  test_func(i));
	return (0);
}
