#include "../push_swap.h"

t_info	sort_only_underfive_a(t_info info)
{
	int	len;

	len = get_stacklen(info.a);
	if (is_sorted(info.a))
		return (info);
	else if (len == 5)
		info = sort_onlyfive_a(info);
	else if (len == 4)
		info = sort_onlyfour_a(info);
	else if (len == 3)
		info = sort_onlythree_a(info);
	else if (len == 2)
		info = sort_two_a(info);
	return (info);
}

t_info	sort_underfive_a(t_info info, int len)
{
	if (is_sorted(info.a))
		return (info);
	if (get_stacklen(info.a) <= 5)
		return (sort_only_underfive_a(info));
	if (len == 5)
		info = sort_five_a(info, len);
	if (len == 4)
		info = sort_four_a(info, len);
	if (len == 3)
		info = sort_three_a(info);
	if (len == 2)
		info = sort_two_a(info);
	//print_info(info);
	return (info);
}
