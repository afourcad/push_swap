#include "ft_printf.h"

int main()
{
	int i = 2;

	if (i-- == 1)
	{
		ft_printf(YELLOW"je suis rouge"EOC);
		ft_printf(RED"Stack A: "EOC);
		ft_printf("\n%d", i);
	}
		ft_printf("\n%d", i);
	return 0;
}
