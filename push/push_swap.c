#include "../push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_info	info;

	info = init_info();
	if (error_check(argc, argv) == -1)
		info.error = -1;
	if (info.error == 0)
		info = make_stacks_connect_node(argc, argv);
	if (info.error == 0)
		info = sort_main(info, argc);
	if (info.error == 0)
		print_operations(info);
	if (info.error == -1)
		print_error();
	all_free(info);
	return (info.error);
}

int	main(int argc, char **argv)
{
	int	i;
	int rtn;

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
	rtn = push_swap(argc, argv);
	return (rtn);
}
