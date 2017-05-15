#include "ft_printf.h"

int main()
{
	int i;


	i = 4;
	if (i > 0)
		while (i-- > 0)
			ft_printf("i = %d\n", i);
	ft_printf("i = %d\n", i);
	return 0;
}
