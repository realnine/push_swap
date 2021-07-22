#include "../push_swap.h"

t_stack	*find_tail(t_stack *x)
{
	if (x)
	{
		while (x->next)
			x = x->next;
	}
	return (x);
}

int	find_overmed(t_stack *stk, int len, int med)
{
	if (!stk)
		return (0);
	while (len && stk)
	{
		if (stk->num >= med)
			return (1);
		stk = stk->next;
		len--;
	}
	return (0);
}

int	find_undermed(t_stack *stk, int len, int med)
{
	if (!stk)
		return (0);
	while (len && stk)
	{
		if (stk->num < med)
			return (1);
		stk = stk->next;
		len--;
	}
	return (0);
}

int	is_sorted(t_stack *x)
{
	if (x)
	{
		while (x->next)
		{
			if (x->num > (x->next)->num)
				return (0);
			x = x->next;
		}
	}
	return (1);
}
