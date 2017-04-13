#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct	s_op
{
	char		*str;
	struct s_op	*next;
}				t_op;

void	ft_free_op(t_op *param)
{
	if (param == NULL)
		return ;
	ft_free_op(param->next);
	free(param);
}

t_op	*ft_new_op(char	*str)
{
	t_op	*list;

	list = malloc(sizeof(*list));
	list->str = ft_strdup(str);
	list->next = NULL;
	return (list);
}

void	ft_add_op(t_op **op, char *str)
{
	if (*op == NULL)
	{
		*op = ft_new_op(str);
		return ;
	}
	ft_add_op(&(*op)->next, str);
}

int	main(int ac, char **av)
{
	char	*tab;
	t_op	*op;

	op = NULL;
	while (get_next_line(0, &tab))
	{
		ft_strjoin(tab, "\0");
		ft_add_op(&op, tab);
	}
	ft_printf("------------------\n");
	while (op != NULL)
	{
		ft_printf("%s\n", op->str);
		op = op->next;
	}
	ft_free_op(op);
	return (0);
}
