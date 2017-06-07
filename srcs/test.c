#include <stdlib.h>

void	ft_fct(int **tab)
{
	*tab  = malloc(sizeof(**tab) * 4);
	(*tab)[0] = 1;
	(*tab)[1] = 2;
	(*tab)[2] = 3;
	(*tab)[3] = 4;
}

int	main ()
{
	int	*tab;

	tab = NULL;
	ft_fct(&tab);
}
