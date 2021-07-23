#include "../push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_info	info;

	info = init_info();
	info.argv = argv;
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
	rtn = push_swap(argc, argv);
	return (rtn);
}
