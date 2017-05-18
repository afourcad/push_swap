#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int main(int ac, char **av)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 1;
	str = NULL;
	while (j < ac)
	{
		i = 0;
		str = ft_strsplit(av[1], ' ');
		while (str[i])
		{
			ft_printf("%s\n", str[i]);
			++i;
		}

	}
	free(str);
	str = NULL;
	return 0;
}
