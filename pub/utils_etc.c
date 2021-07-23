#include "../push_swap.h"

void	pill_arr(int *arr, t_stack *x, int len)
{
	int	i;

	i = 0;
	while (i < len && x)
	{
		arr[i++] = x->num;
		x = x->next;
	}
}

void	stack_free(t_stack *x)
{
	t_stack	*tmp;

	tmp = NULL;
	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

t_stack	*create_node(void)
{
	t_stack	*x;

	x = (t_stack *)malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x->num = 0;
	x->prev = NULL;
	x->next = NULL;
	return (x);
}

void	all_free(t_info info)
{
	int	i;

	if (info.a)
		stack_free(info.a);
	if (info.b)
		stack_free(info.b);
	if (info.op)
		free(info.op);
	i = 0;
	if (info.argv)
	{
		while (info.argv[i])
		{
			free(info.argv[i]);
			i++;
		}
	}
}

t_info	init_info(void)
{
	t_info	info;

	info.error = 0;
	info.check = 0;
	info.op = NULL;
	info.a = NULL;
	info.b = NULL;
	return (info);
}
