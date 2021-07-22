#include "../push_swap.h"

t_info	ch_ss(t_info info)
{
	info = ch_sa(info);
	info = ch_sb(info);
	return (info);
}

t_info	ch_rr(t_info info)
{
	info = ch_ra(info);
	info = ch_rb(info);
	return (info);
}

t_info	ch_rrr(t_info info)
{
	info = ch_rra(info);
	info = ch_rrb(info);
	return (info);
}