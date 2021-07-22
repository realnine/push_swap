#include "../push_swap.h"

t_info	re_sort_a_b(t_info info, int a_len, int b_len)
{
	if (a_len > 0 && a_len <= 5)
		info = sort_underfive_a(info, a_len);
	else if (a_len > 5)
		info = sort_main(info, a_len);
	if (b_len > 0 && b_len <= 5)
		info = sort_underfive_btoa(info, b_len);
	else if (b_len > 5)
		info = sort_back_btoa(info, b_len);
	return (info);
}

t_info	sort_underfive_rrb_btoa(t_info info, int len)
{
	int	med;
	int	i;
	int	stack_len;

	i = len;
	stack_len = get_stacklen(info.b);
	med = get_med_from_end(info.b, len, info);
	while (stack_len == len && i--)
	{
		if (info.b->num >= med)
			info = pa(info);
		else
			info = rb(info);
	}
	while (stack_len != len && i--)
	{
		info = rrb(info);
		if (info.b->num >= med)
			info = pa(info);
	}
	info = re_sort_a_b(info, (len / 2) + (len % 2), (len / 2));
	return (info);
}

t_info	sort_underfive_btoa(t_info info, int len)
{
	int	n;

	n = get_stacklen(info.b);
	if (len > n)
		len = n;
	if (len == 1 && n >= 1)
		info = pa(info);
	else if (len == 2 && n >= 2)
		info = sort_two_btoa(info);
	else if (len == 3 && n >= 3)
		info = sort_three_btoa(info, len);
	else if (len == 4 && n >= 4)
		info = sort_four_btoa(info, len);
	else if (len == 5 && n >= 5)
		info = sort_five_btoa(info, len);
	//print_info(info);
	return (info);
}
