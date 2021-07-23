#include "../push_swap.h"

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	*free_arg_arr(char *arg, char *arr, char *tmp)
{
	free(arg);
	free(arr);
	return (tmp);
}

int	error_return(char *line, t_info info)
{
	free(line);
	all_free(info);
	return (print_error());
}

int	error_free(t_info info, char **argv)
{
	info.argv = argv;
	all_free(info);
	return (print_error());
}
