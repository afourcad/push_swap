#include "libft.h"

int	main()
{
	char **tmp;

	tmp = malloc(sizeof(**tmp) * 3);
	((*tmp)) = malloc(sizeof(*tmp) * 5);
	((*tmp) + 1) = malloc(sizeof(*tmp) * 5);
	((*tmp) + 2) = malloc(sizeof(*tmp) * 5);
	((*tmp) + 3) = NULL;
	ft_str_multi_free(&tmp);
}
