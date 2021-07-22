#include "../push_swap.h"

t_stack *make_stacks_reverse_connect_node(t_stack *cur)
{
	t_stack *nex;

	while (cur->prev)
	{
		nex = cur;
		cur = cur->prev;
		cur->next = nex;
	}
	return (cur);
}

t_info make_stacks_connect_node(int argc, char **argv)
{
	t_info info;
	t_stack *cur;
	t_stack *pre;
	int i;

	info = init_info();
	pre = NULL;
	i = 0;
	while (i < argc)
	{
		cur = create_node();
		if (!cur)
		{
			info.error = -1;
			return (info);
		}
		cur->num = ft_atoi(argv[i++]);
		cur->prev = pre;
		pre = cur;
	}
	info.a = make_stacks_reverse_connect_node(cur);
	return (info);
}