#include "../push_swap.h"

void	quick_sort(int *target, int left, int right)
{
	int	i;
	int	j;
	int	tmp;
	int	pivot;

	if (left >= right)
		return ;
	i = left;
	j = right;
	pivot = target[(left + right) / 2];
	while (1)
	{
		while (target[i] < pivot)
			i++;
		while (pivot < target[j])
			j--;
		if (i >= j)
			break ;
		tmp = target[i];
		target[i++] = target[j];
		target[j--] = tmp;
	}
	quick_sort(target, left, i - 1);
	quick_sort(target, j + 1, right);
}
