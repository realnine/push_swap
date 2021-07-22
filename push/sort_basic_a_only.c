#include "../push_swap.h"

t_info	sort_onlythree_a(t_info info)
{
	int	med;

	if (get_stacklen(info.a) == 3)
	{
		med = get_med(info.a, get_stacklen(info.a), info);
		if (!is_sorted(info.a))
		{
			if (info.a->num > med)
				info = ra(info);
			else if (info.a->next->num > med)
				info = rra(info);
			if (info.a->num == med)
				info = sa(info);
		}
	}
	return (info);
}

t_info	sort_onlyfour_a(t_info info)
{
	t_stack	*tail;
	int		med;
	int		min;

	tail = find_tail(info.a);
	med = get_med(info.a, get_stacklen(info.a), info);
	min = get_min(info.a, get_stacklen(info.a));
	if (info.a->num < med
		|| info.a->num == get_max(info.a, get_stacklen(info.a)))
		info = pb(info);
	else if (tail->num < med || info.a->next->num < med)
	{
		if (info.a->next->num < med && tail->num != min)
			info = sa(info);
		else if (tail->num < med && info.a->next->num != min)
			info = rra(info);
		info = pb(info);
	}
	info = sort_onlythree_a(info);
	info = pa(info);
	if (info.a->num == get_max(info.a, get_stacklen(info.a)))
		info = ra(info);
	else if (info.a->num > info.a->next->num)
		info = sa(info);
	return (info);
}

t_info	fick_and_pb(t_info info, int min, int med, int max)
{
	t_stack	*tail;

	tail = find_tail(info.a);
	if (info.a->num < med || info.a->num == max)
		info = pb(info);
	else if (tail->num < med || info.a->next->num < med
		|| tail->num == max || info.a->next->num == max)
	{
		if ((info.a->next->num < med && tail->num != min)
			|| (info.a->next->num == max && tail->num != min))
			info = sa(info);
		else if ((tail->num < med && info.a->next->num != min)
			|| (tail->num == max && info.a->next->num != min))
			info = rra(info);
		info = pb(info);
	}
	return (info);
}

t_info	sort_onlyfive_a(t_info info)
{
	int		med;
	int		min;
	int		max;

	med = get_med(info.a, get_stacklen(info.a), info);
	min = get_min(info.a, get_stacklen(info.a));
	max = get_max(info.a, get_stacklen(info.a));
	info = fick_and_pb(info, min, med, max);
	info = sort_onlyfour_a(info);
	info = pa(info);
	if (info.a->num == max)
		info = ra(info);
	else if (info.a->num > info.a->next->num)
		info = sa(info);
	return (info);
}
