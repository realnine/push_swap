#include "../push_swap.h"

t_info	ch_sb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
			do_swap(info.b);
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

t_info	ch_pb(t_info info)
{
	if (info.a)
		info = pb_connection(info, info.a);
	return (info);
}

t_info	ch_rb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
			info.b = do_rotate(info.b);
	}
	return (info);
}

t_info	ch_rrb(t_info info)
{
	if (info.b)
	{
		if (info.b->next)
			info.b = do_rrotate(info.b);
	}
	return (info);
}
