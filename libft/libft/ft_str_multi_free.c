#include <stdlib.h>
#include "libft.h"

void	ft_str_multi_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		ft_strdel(&((*str)[i]));
		++i;
	}
	free(*str);
	*str = NULL;
}
