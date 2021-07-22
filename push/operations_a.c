#include "../push_swap.h"

t_info	sa(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			do_swap(info.a);
			info = input_operations(info, "sa ");
		}
	}
	return (info);
}

t_info	pa_connection(t_info info, t_stack *x)
{
	if (x->next)
	{
		(x->next)->prev = NULL;
		info.b = x->next;
	}
	else
		info.b = NULL;
	if (info.a)
	{
		x->next = info.a;
		info.a->prev = x;
		info.a = x;
	}
	else
	{
		x->next = NULL;
		info.a = x;
	}
	return (info);
}

t_info	pa(t_info info)
{
	if (info.b)
	{
		info = pa_connection(info, info.b);
		info = input_operations(info, "pa ");
	}
	return (info);
}

t_info	ra(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			info.a = do_rotate(info.a);
			info = input_operations(info, "ra ");
		}
	}
	return (info);
}

t_info	rra(t_info info)
{
	if (info.a)
	{
		if (info.a->next)
		{
			info.a = do_rrotate(info.a);
			info = input_operations(info, "rra ");
		}
	}
	return (info);
}
