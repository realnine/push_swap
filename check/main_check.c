#include "../push_swap.h"

t_info	check_s_p_operation(t_info info, char *line)
{
	info.check = 0;
	if (ft_strcmp(line, "sa") == 0)
		info = ch_sa(info);
	else if (ft_strcmp(line, "sb") == 0)
		info = ch_sb(info);
	else if (ft_strcmp(line, "pa") == 0)
		info = ch_pa(info);
	else if (ft_strcmp(line, "pb") == 0)
		info = ch_pb(info);
	else if (ft_strcmp(line, "ss") == 0)
		info = ch_ss(info);
	else
		info.check = 1;
	return (info);
}

t_info	check_r_rr_operation(t_info info, char *line)
{
	info.check = 0;
	if (ft_strcmp(line, "ra") == 0)
		info = ch_ra(info);
	else if (ft_strcmp(line, "rb") == 0)
		info = ch_rb(info);
	else if (ft_strcmp(line, "rra") == 0)
		info = ch_rra(info);
	else if (ft_strcmp(line, "rrb") == 0)
		info = ch_rrb(info);
	else if (ft_strcmp(line, "rr") == 0)
		info = ch_rr(info);
	else if (ft_strcmp(line, "rrr") == 0)
		info = ch_rrr(info);
	else
		info.check = 1;
	return (info);
}

int	checker(int argc, char **argv)
{
	t_info	info;
	char	*line;

	info = init_info();
	if (error_check(argc, argv) == -1)
		return (error_free(info, argv));
	info = make_stacks_connect_node(argc, argv);
	while (get_next_line(0, &line))
	{
		info = check_s_p_operation(info, line);
		if (info.check == 1)
			info = check_r_rr_operation(info, line);
		if (info.check == 1)
			return (error_return(line, info));
		free(line);
		line = NULL;
	}
	if (is_sorted(info.a))
		printf("OK\n");
	else
		printf("KO\n");
	all_free(info);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		rtn;
	char	*arg;
	char	*arr;
	char	*tmp;

	if (argc <= 1)
		return (0);
	else if (argc >= 2)
	{
		arr = NULL;
		i = 1;
		while (i < argc)
		{
			arg = ft_strjoin(argv[i++], " ");
			tmp = ft_strjoin(arr, arg);
			arr = free_arg_arr(arg, arr, tmp);
		}
		argv = ft_split(arr, ' ');
		argc = argv_len(argv);
		free(tmp);
	}
	rtn = checker(argc, argv);
	return (rtn);
}
