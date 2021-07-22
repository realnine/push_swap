#include "../push_swap.h"

int	check_is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	val;
	int	arr[argc];
	int	index;

	j = 0;
	while (j < argc)
		arr[j++] = 0;
	i = 0;
	index = 0;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		j = 0;
		while (j < index)
		{
			if (arr[j++] == val)
				return (-1);
		}
		arr[index++] = val;
		i++;
	}
	return (0);
}

int	check_int_size(int argc, char **argv)
{
	int	i;
	int	val;

	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 9)
		{
			val = ft_atoi(argv[i]);
			if (val == -1 || val == 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	error_check(int argc, char **argv)
{
	int	error;

	error = 0;
	if (check_is_digit(argc, argv) == -1)
		error = -1;
	else if (check_int_size(argc, argv) == -1)
		error = -1;
	else if (check_duplicate(argc, argv) == -1)
		error = -1;
	return (error);
}
