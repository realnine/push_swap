#include "../push_swap.h"

t_info	sb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			do_swap(info.b);
			info = input_operations(info, "sb ");
		}
	}
	return (info);
}

t_info	pb_connection(t_info info, t_stack *x)
{
	if (x->next)
	{
		(x->next)->prev = NULL;
		info.a = x->next;
	}
	else
		info.a = NULL;
	if (info.b)
	{
		x->next = info.b;
		info.b->prev = x;
		info.b = x;
	}
	else
	{
		x->next = NULL;
		info.b = x;
	}
	return (info);
}

t_info	pb(t_info info)
{
	if (info.a)
	{
		info = pb_connection(info, info.a);
		info = input_operations(info, "pb ");
	}
	return (info);
}

t_info	rb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			info.b = do_rotate(info.b);
			info = input_operations(info, "rb ");
		}
	}
	return (info);
}

t_info	rrb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
		{
			info.b = do_rrotate(info.b);
			info = input_operations(info, "rrb ");
		}
	}
	return (info);
}
