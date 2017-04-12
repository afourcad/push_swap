#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*tab;

	while (get_next_line(1, &tab))
		ft_printf("J'ai lu\n");
	return (0);
}
