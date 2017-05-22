#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "checker.h"

void	ft_afficher(t_head *a, t_head *b, char *flags)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;

	tmp_a = a->beg;
	tmp_b = b->beg;
	i = 0;
	if (!flags || !FLG_V)
		return ;
	ft_printf(RED"Stack A: "EOC);
	while (i++ < a->size)
	{
		ft_printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	i = 0;
	ft_printf("\n");
	ft_printf(RED"Stack B: "EOC);
	while (i++ < b->size)
	{
		ft_printf("%d ", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	ft_printf("\n\n");
}
