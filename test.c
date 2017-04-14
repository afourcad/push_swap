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

int	main(int ac, char **av)
{
	char	*tab;
	t_stack	*a;
	t_stack	*b;
	t_stack	*op;

	op = NULL;
	tab = NULL;
	a = NULL;
	b = NULL;
	ft_printf("ac: %d\n", ac);
	if (ac > 1)
	{
		ft_set_stack(&a, &b, ac, av);
		while ((get_next_line(0, &tab)) > 0)
			ft_add_op(&op, tab);
		ft_printf("------------------\n");
		while (op != NULL)
		{
			ft_printf("%s\n", op->nbr);
			op = op->next;
		}
		ft_free_op(op);
	}
	return (0);
}
