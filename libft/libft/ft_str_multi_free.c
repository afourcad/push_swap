#include <stdlib.h>

void	ft_str_multi_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		++i;
	}
	*str = NULL;
}
