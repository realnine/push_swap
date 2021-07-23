#include "../push_swap.h"

t_info	split_atob(t_info info, int len)
{
	int	med;
	int	cnt;
	int	i;

	i = len;
	cnt = 0;
	med = get_med(info.a, len, info);
	while (find_undermed(info.a, i--, med))
	{
		if (info.a->num < med)
			info = pb(info);
		else
		{
			info = ra(info);
			cnt++;
		}
	}
	if (get_stacklen(info.a) > len)
	{
		while (cnt--)
			info = rra(info);
	}
	return (info);
}

t_info	sort_back_btoa(t_info info, int len)
{
	int	med;
	int	a_len;
	int	b_len;

	a_len = (len / 2) + (len % 2);
	b_len = len / 2;
	if (len <= 5)
		info = sort_underfive_btoa(info, len);
	else
	{
		med = get_med(info.b, len, info);
		while (len--)
		{
			if (info.b->num >= med)
				info = pa(info);
			else
				info = rb(info);
		}
		info = sort_main(info, a_len);
		info = sort_underfive_rrb_btoa(info, b_len);
	}
	return (info);
}

t_info	sort_main(t_info info, int len)
{
	int	a_len;
	int	b_len;

	if (is_sorted(info.a))
		return (info);
	if (len > 5)
	{
		a_len = (len / 2) + (len % 2);
		b_len = len / 2;
		info = split_atob(info, len);
		if (a_len > 5)
			info = sort_main(info, a_len);
		else
			info = sort_underfive_a(info, a_len);
		info = sort_back_btoa(info, b_len);
	}
	else
		info = sort_underfive_a(info, len);
	return (info);
}
