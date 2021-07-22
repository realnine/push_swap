#include "../push_swap.h"

t_info	sort_two_btoa(t_info info)
{
	info = pa(info);
	info = pa(info);
	info = sort_two_a(info);
	return (info);
}

t_info	sort_three_btoa(t_info info, int len)
{
	int	med;
	int	min;

	med = get_med(info.b, 3, info);
	min = get_min(info.b, 3);
	while (find_overmed(info.b, len, med))
	{
		if (info.b->num != min)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_two_a(info);
	if (len == 0)
		info = rrb(info);
	info = pa(info);
	return (info);
}

t_info	back_and_send(t_info info, int len, int min)
{
	int	cnt_rb;

	cnt_rb = 2 - len;
	while (cnt_rb-- > 0)
	{
		if (len == 1 && info.b->num != min)
		{
			info = pa(info);
			len--;
		}
		info = rrb(info);
		len++;
	}
	if (len)
		info = sort_underfive_btoa(info, len);
	return (info);
}

t_info	sort_four_btoa(t_info info, int len)
{
	int	med;
	int	min;

	med = get_med(info.b, 4, info);
	min = get_min(info.b, 4);
	while (find_overmed(info.b, len, med))
	{
		if (info.b->num >= med)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_two_a(info);
	info = back_and_send(info, len, min);
	return (info);
}

t_info	sort_five_btoa(t_info info, int len)
{
	int	med;
	int	min;

	med = get_med(info.b, 5, info);
	min = get_min(info.b, 5);
	while (find_overmed(info.b, len, med))
	{
		if (info.b->num >= med)
			info = pa(info);
		else
			info = rb(info);
		len--;
	}
	info = sort_three_a(info);
	info = back_and_send(info, len, min);
	return (info);
}
