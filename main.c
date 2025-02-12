#include "push_swap.h"

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

// int main()
// {
//     t_stack *node1;
//     t_stack *node2;
//     t_stack *node3;
//     t_stack *node4;

//     node1 = ft_lstnew(8);
//     node2 = ft_lstnew(9);
//     node3 = ft_lstnew(2);
//     node4 = ft_lstnew(5);
//     t_stack *a = NULL;

//     ft_lstadd_back(&a, node1);
//     ft_lstadd_back(&a, node2);
//     ft_lstadd_back(&a, node3);
//     ft_lstadd_back(&a, node4);

//     t_stack *b = NULL;

//     node1 = ft_lstnew(1);
//     node2 = ft_lstnew(9);
//     node3 = ft_lstnew(90);
//     node4 = ft_lstnew(4);

//     ft_lstadd_back(&b, node1);
//     ft_lstadd_back(&b, node2);
//     ft_lstadd_back(&b, node3);
//     ft_lstadd_back(&b, node4);

//     print_stack(a);
//     sa(&a);
//     print_stack(a);
//     ra(&a);
//     print_stack(a);
//     rra(&a);
//     print_stack(a);
//     printf("---------------------------------------------------\n");
//     print_stack(b);
//    pa(&a, &b);
//    print_stack(a);
//    print_stack(b);
//     pb(&a, &b);
//     print_stack(a);
//     print_stack(b);
//     rb(&b);
//     print_stack(b);
//     sb(&b);
//     print_stack(b);
//     printf("---------------------------------------------------\n");
//     print_stack(a);
//     print_stack(b);
//     ss(&a, &b);
//     print_stack(a);
//     print_stack(b);
//     printf("----------------------------algo sorting tests---------------------------------\n");
//     t_stack *t;
//     t = NULL;
//     t_stack *nod1 = ft_lstnew(1);
//     t_stack *nod2 = ft_lstnew(9);
//     t_stack *nod3 = ft_lstnew(8);
//     ft_lstadd_back(&t, nod1);
//     ft_lstadd_back(&t, nod2);
//     ft_lstadd_back(&t, nod3);
//     print_stack(t);
//     algo_for3_elements(&t);
//     print_stack(t);
//     printf("-----------for 4 elements--------------\n");
//     t_stack *s;
//     s = NULL;
//     nod1 = ft_lstnew(2);
//     nod2 = ft_lstnew(3);
//     nod3 = ft_lstnew(4);
//     t_stack *nod4 = ft_lstnew(1);
//     ft_lstadd_back(&s, nod1);
//     ft_lstadd_back(&s, nod2);
//     ft_lstadd_back(&s, nod3);
//     ft_lstadd_back(&s, nod4);
//     print_stack(s);
//     algo_for4_elements(&s);
//     print_stack(s);
//     printf("-------------------for 5 elements---------------------\n");
//     t_stack *f;
//     f = NULL;
//     t_stack *m = ft_lstnew(3); 
//     t_stack *p = ft_lstnew(4);
//     t_stack *c = ft_lstnew(1);
//     t_stack *d = ft_lstnew(5);
//     t_stack *z = ft_lstnew(2);
//     ft_lstadd_back(&f, m);
//     ft_lstadd_back(&f, p);
//     ft_lstadd_back(&f, c);
//     ft_lstadd_back(&f, d);
//     ft_lstadd_back(&f, z);
//     print_stack(f);
//     algo_for5_elements(&f);
//     print_stack(f);
//     printf("----------------------for 6 elements and more-----------------------\n");

// }

void	free_split(char **str_str)
{
	int	i;

	if (!str_str)
		return ;
	i = 0;
	while (str_str[i])
	{
		free(str_str[i]);
		i++;
	}
	free(str_str);
}

int *sort_array(int *array, int ac, char **s)
{
    int size;
    int j;
    int *r;

    size = ac - 1;
    j = 0;
    int count = 0;
    while( s[count])
        count ++;
    // printf("ac == %d , count = %d \n",ac, count);
    array = malloc(count * sizeof(int));
    if(!array)
        return (0);
    while (s[j] )
    {   
        // printf("s = %s \n",s[j]);
        array[j] = ft_atoi(s[j]);
        j++;
    }
    r = ft_bubble_sort(array, size);
    return(r);
}

int main(int argc, char **argv)
{
   // int i;
    char **s;
    char *join;
    t_stack *ss;
   // t_stack *tmp;
   t_stack *b;
    int *array;
    //int size;
   // int j;
    int *r;
    
    //i = 1;
    b = NULL;
    array = 0;
    if(argc < 2)
        return (0);
    
    join = join_args(argc, argv);
   // printf("%s join args\n", join);
    //size = argc - 1;
   // printf("size of input : %d\n", size);
    // array = malloc(size * sizeof(int));
    // if(!array)
    //     return (0);
   // j = 0;
   // printf("joining args : %s\n", join); 
    s = ft_split(join, ' '); 
    // int k = 0;
    // while (s[k])
    // {
    //     printf("-----> %s \n",s[k]);
    //     k++;
    // }
    
    // for(int k = 0; k <= 100; k++)
    // {
    //     printf("split [%d]:%s\t ", k,s[k]);
    // }
    // while (s[j])
    // {   
    //     array[j] = ft_atoi(s[j]);
    //     j++;
    // }
   // r = ft_bubble_sort(array, size);
    check_error(argc, s);
    r = sort_array(array, argc, s);
    // j = 0;
    // while (j < size)
    // {   
    //     printf("[%d]\t", r[j]);
    //     j++;
    // }
    ss = init_stack(s);
    int count  = 0;
    while(s[count])
        count ++;
    printf("\n count = %d \n",count);
    if(count == 2)
        algo_for2_elements(&ss);
    else if(count == 3)
        algo_for3_elements(&ss);
    else if(count == 4)
        algo_for4_elements(&ss);
    else if(count == 5)
        algo_for5_elements(&ss);
    else
        push_to_b(&ss, r, &b);
    // int u = is_sorted(&ss);
    // if(u == 0)
    //     exit(0);
    // t_stack *tmp = ss;
    // printf("\nbefore processing-----\n");
    // while(tmp != NULL)call of silence
    // {
    //     printf("%d-> ", tmp->data);
    //     tmp = tmp-> next;
    // }printf("NULL");
    //printf("\nafter processing-----\n");
    //printf("test\n");
    //algo_for3_elements(&ss);
    t_stack *tmp1;
    //algo_for4_elements(&ss);
    //push_to_b(&ss, r, &b);
    tmp1 = ss;
    while(tmp1 != NULL)
    {
        printf("%d--->", tmp1->data);
        tmp1 = tmp1-> next;
    }printf("NULL");
    ft_lstclear(&ss);
    free(r);
    free(join);
    ft_free(s);
    //printf("\n------end of program--------");
}
//./push_swap 0 1 2 l1 3 