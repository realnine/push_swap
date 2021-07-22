#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	int				error;
	char			*op;
	struct s_stack	*a;
	struct s_stack	*b;
}	t_info;

//main
t_info	sort_main(t_info info, int len);
t_info	sort_back_btoa(t_info info, int len);
int		error_check(int argc, char **argv);
t_info	make_stacks_connect_node(int argc, char **argv);

//utils
int		is_sorted(t_stack *x);
t_stack	*find_tail(t_stack *x);
int		get_stacklen(t_stack *x);
void	pill_arr(int *arr, t_stack *x, int len);
int		get_max(t_stack *x, int len);
int		get_min(t_stack *x, int len);
int		get_med(t_stack *x, int len, t_info info);
int		get_med_from_end(t_stack *b, int len, t_info info);

int		find_undermed(t_stack *stk, int len, int med);
int		find_overmed(t_stack *stk, int len, int med);
void	stack_free(t_stack *x);
void	all_free(t_info info);
t_stack	*create_node(void);
t_info	init_info(void);

//void push_swap(int argc, char **argv);
void	quick_sort(int *target, int left, int right);

// operations
void	do_swap(t_stack *x);
t_stack	*do_rotate(t_stack *x);
t_stack	*do_rrotate(t_stack *x);
t_info	sa(t_info info);
t_info	sb(t_info info);
t_info	pa(t_info info);
t_info	pb(t_info info);
t_info	ra(t_info info);
t_info	rb(t_info info);
t_info	rra(t_info info);
t_info	rrb(t_info info);
t_info	ch_sa(t_info info);
t_info	ch_sb(t_info info);
t_info	ch_pa(t_info info);
t_info	ch_pb(t_info info);
t_info	ch_ra(t_info info);
t_info	ch_rb(t_info info);
t_info	ch_rra(t_info info);
t_info	ch_rrb(t_info info);
t_info	ch_ss(t_info info);
t_info	ch_rr(t_info info);
t_info	ch_rrr(t_info info);


//basic_sort
t_info	sort_two_a(t_info info);
t_info	sort_three_a(t_info info);
t_info	sort_four_a(t_info info, int len);
t_info	sort_five_a(t_info info, int len);

t_info	sort_onlythree_a(t_info info);
t_info	sort_onlyfour_a(t_info info);
t_info	sort_onlyfive_a(t_info info);

t_info	sort_two_btoa(t_info info);
t_info	sort_three_btoa(t_info info, int len);
t_info	sort_four_btoa(t_info info, int len);
t_info	sort_five_btoa(t_info info, int len);

t_info	sort_only_underfive_a(t_info info);
t_info	sort_underfive_a(t_info info, int len);
t_info	sort_underfive_btoa(t_info info, int len);
t_info	sort_underfive_rrb_btoa(t_info info, int len);

// print funcs
void	print_arr(int *arr, int len);
void	print_info(t_info info);
void	print_stack(t_stack *x, char *name);
void	print_operations(t_info info);
t_info	input_operations(t_info info, char *op);
int		print_error(void);

#endif