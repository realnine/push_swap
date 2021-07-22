#include "../push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

t_info	input_operations(t_info info, char *op)
{
	char	*tmp;

	if (!info.op)
		info.op = ft_strdup(op);
	else
	{
		tmp = info.op;
		info.op = ft_strjoin(info.op, op);
		free(tmp);
	}
	if (!info.op)
		info.error = -1;
	return (info);
}

char	*put_operation(char *ptr, char *op, int op_len)
{
	write(1, op, ft_strlen(op));
	return (ptr + (sizeof(char) * op_len));
}

char	*check_duplication_op(char *s)
{
	if (ft_strncmp(s, "sa sb ", 6) == 0 || ft_strncmp(s, "sb sa ", 6) == 0)
		s = put_operation(s, "ss\n", 6);
	else if (ft_strncmp(s, "ra rb ", 6) == 0 || ft_strncmp(s, "rb ra ", 6) == 0)
		s = put_operation(s, "rr\n", 6);
	else if (ft_strncmp(s, "rra rrb ", 8) == 0
		|| ft_strncmp(s, "rrb rra ", 8) == 0)
		s = put_operation(s, "rrr\n", 8);
	return (s);
}

char	*check_op(char *s)
{
	if (ft_strncmp(s, "sa ", 3) == 0)
		s = put_operation(s, "sa\n", 3);
	else if (ft_strncmp(s, "sb ", 3) == 0)
		s = put_operation(s, "sb\n", 3);
	else if (ft_strncmp(s, "ra ", 3) == 0)
		s = put_operation(s, "ra\n", 3);
	else if (ft_strncmp(s, "rb ", 3) == 0)
		s = put_operation(s, "rb\n", 3);
	else if (ft_strncmp(s, "pa ", 3) == 0)
		s = put_operation(s, "pa\n", 3);
	else if (ft_strncmp(s, "pb ", 3) == 0)
		s = put_operation(s, "pb\n", 3);
	else if (ft_strncmp(s, "rra ", 4) == 0)
		s = put_operation(s, "rra\n", 4);
	else if (ft_strncmp(s, "rrb ", 4) == 0)
		s = put_operation(s, "rrb\n", 4);
	return (s);
}

void	print_operations(t_info info)
{
	char	*s;
	char	*tmp;

	tmp = NULL;
	s = info.op;
	while (s)
	{
		if (!*s)
			break ;
		while (tmp != s)
		{
			tmp = s;
			s = check_duplication_op(s);
		}
		s = check_op(s);
	}
}
