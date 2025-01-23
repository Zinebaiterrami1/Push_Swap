#include "push_swap.h"

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main()
{
    t_stack *node1;
    t_stack *node2;
    t_stack *node3;
    t_stack *node4;

    node1 = ft_lstnew(8);
    node2 = ft_lstnew(9);
    node3 = ft_lstnew(2);
    node4 = ft_lstnew(5);
    t_stack *a = NULL;

    ft_lstadd_back(&a, node1);
    ft_lstadd_back(&a, node2);
    ft_lstadd_back(&a, node3);
    ft_lstadd_back(&a, node4);

    t_stack *b = NULL;

    node1 = ft_lstnew(1);
    node2 = ft_lstnew(9);
    node3 = ft_lstnew(90);
    node4 = ft_lstnew(4);

    ft_lstadd_back(&b, node1);
    ft_lstadd_back(&b, node2);
    ft_lstadd_back(&b, node3);
    ft_lstadd_back(&b, node4);

    print_stack(a);
    sa(&a);
    print_stack(a);
    ra(&a);
    print_stack(a);
    rra(&a);
    print_stack(a);
    printf("---------------------------------------------------\n");
    print_stack(b);
   pa(&a, &b);
   print_stack(a);
   print_stack(b);
    pb(&a, &b);
    print_stack(a);
    print_stack(b);
    rb(&b);
    print_stack(b);
    sb(&b);
    print_stack(b);
    printf("---------------------------------------------------\n");
    print_stack(a);
    print_stack(b);
    ss(&a, &b);
    print_stack(a);
    print_stack(b);
    printf("----------------------------algo sorting tests---------------------------------\n");
    t_stack *t;
    t = NULL;
    t_stack *nod1 = ft_lstnew(1);
    t_stack *nod2 = ft_lstnew(9);
    t_stack *nod3 = ft_lstnew(8);
    ft_lstadd_back(&t, nod1);
    ft_lstadd_back(&t, nod2);
    ft_lstadd_back(&t, nod3);
    print_stack(t);
    algo_for3_elements(&t);
    print_stack(t);
    printf("-----------for 4 elements--------------\n");
    t_stack *s;
    s = NULL;
    nod1 = ft_lstnew(2);
    nod2 = ft_lstnew(3);
    nod3 = ft_lstnew(4);
    t_stack *nod4 = ft_lstnew(1);
    ft_lstadd_back(&s, nod1);
    ft_lstadd_back(&s, nod2);
    ft_lstadd_back(&s, nod3);
    ft_lstadd_back(&s, nod4);
    print_stack(s);
    algo_for4_elements(&s);
    print_stack(s);
    printf("-------------------for 5 elements---------------------\n");
    t_stack *f;
    f = NULL;
    t_stack *m = ft_lstnew(3); 
    t_stack *p = ft_lstnew(4);
    t_stack *c = ft_lstnew(1);
    t_stack *d = ft_lstnew(5);
    t_stack *z = ft_lstnew(2);
    ft_lstadd_back(&f, m);
    ft_lstadd_back(&f, p);
    ft_lstadd_back(&f, c);
    ft_lstadd_back(&f, d);
    ft_lstadd_back(&f, z);
    print_stack(f);
    algo_for5_elements(&f);
    print_stack(f);
    printf("----------------------for 6 elements and more-----------------------\n");

}

