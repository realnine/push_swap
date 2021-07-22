#include "../push_swap.h"

void print_arr(int *arr, int len)
{   
    int i;
    
    printf("arr = ");
    i = 0;
    while (i < len)
    {
        printf("[%d] ", arr[i++]);
    }
    printf("\n");
}

void print_stack(t_stack *x, char *name)
{
    if (x)
    {
        printf("%s: [ ", name);
        while (x)
        {
            printf("%d ", x->num);
            x = x->next;
        }
        printf("]\n");
    }
    else
    {
        printf("%s: [ NULL ]\n", name);
    }
}

void print_info(t_info info)
{
    print_stack(info.a, "stack a");
    print_stack(info.b, "stack b");
    printf("--------------\n");
}