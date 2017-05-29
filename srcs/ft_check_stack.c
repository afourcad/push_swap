#include "libft.h"
#include "checker.h"

int		ft_check_if_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (ft_isdigit(str[1]) != 1)
			return (ft_error());
		++i;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (ft_error());
		++i;
	}
	return (1);
}

int		ft_no_duplicate(t_head *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		j;

	tmp = head->beg;
	i = 0;
	if (head->beg == head->end)
		return (1);
	while (i < head->size)
	{
		j = i + 1;
		tmp2 = tmp->next;
		while (j < head->size)
		{
			if (tmp->nbr == tmp2->nbr
				|| tmp2->nbr > INT_MAX || tmp2->nbr < INT_MIN)
				return (ft_error());
			tmp2 = tmp2->next;
			++j;
		}
		tmp = tmp->next;
		++i;
	}
	return (1);
}
