#include "../push_swap.h"

int	check_s_p_operation(t_info *info, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		*info = ch_sa(*info);
	else if (ft_strcmp(line, "sb") == 0)
		*info = ch_sb(*info);
	else if (ft_strcmp(line, "pa") == 0)
		*info = ch_pa(*info);
	else if (ft_strcmp(line, "pb") == 0)
		*info = ch_pb(*info);
	else if (ft_strcmp(line, "ss") == 0)
		*info = ch_ss(*info);
	else
		return (0);
	return (1);
}

int	check_r_rr_operation(t_info *info, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		*info = ch_ra(*info);
	else if (ft_strcmp(line, "rb") == 0)
		*info = ch_rb(*info);
	else if (ft_strcmp(line, "rra") == 0)
		*info = ch_rra(*info);
	else if (ft_strcmp(line, "rrb") == 0)
		*info = ch_rrb(*info);

	else if (ft_strcmp(line, "rr") == 0)
		*info = ch_rr(*info);
	else if (ft_strcmp(line, "rrr") == 0)
		*info = ch_rrr(*info);
	else
		return (0);
	return (1);
}

int	checker(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int		check;

	info = init_info();
	if (error_check(argc, argv) == -1)
		return (print_error());
	info = make_stacks_connect_node(argc, argv);
	while (get_next_line(0, &line))
	{
		check = 0;
		check = check_s_p_operation(&info, line);
		if (check == 0)
			check = check_r_rr_operation(&info, line);
		if (check == 0)
			return (print_error());
		free(line);
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
	int	i;
	int	rtn;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (-1);
		i = 0;
		while (argv[i])
			i++;
		argc = i;
	}
	else if (argc > 2)
	{
		argv = &argv[1];
		argc--;
	}
	rtn = checker(argc, argv);
	return (rtn);
}