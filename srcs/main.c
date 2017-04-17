#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"


void	ft_free_op(t_stack *param)
{
	if (param == NULL)
		return ;
	ft_free_op(param->next);
	free(param);
}

int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	char	*tab;
	t_stack	*a;
	t_stack	*b;

	tab = NULL;
	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if ((ft_set_stack(&a, av)) == 0)
			return (0);
		while ((get_next_line(0, &tab)) > 0)
			if ((ft_do_opperations(&a, &b, tab)) == 0)
				return (0);
			;
		if ((ft_is_sort(a, b)) == ERROR)
			return (0);
		while (a != NULL)
		{
			ft_printf("%s ", a->nbr);
			a = a->next;
		}
		ft_printf("\n");
		while (b != NULL)
		{
			ft_printf("%s ", b->nbr);
			b = b->next;
		}
		ft_free_op(a);
		ft_free_op(b);
	}
	return (0);
}
