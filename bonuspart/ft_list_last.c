#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

// то что помогает распечатать связанный список 
void ft_print_list(t_list *head)
{
    t_list *current = head;
    printf(" head: %p \n", head);
    while(current != NULL)
    {   
        printf(" pointer of node: %p , data: %d \n", current->next, *((int*)current->data));
        current = current->next;
    }    
    
}

t_list *ft_list_last(t_list *begin_list)
{
    while(begin_list != NULL)
    {
        begin_list=begin_list->next;
        if (begin_list->next == NULL)
            return(begin_list);
    }
    return(begin_list);
}

// функция main носит чисто проверочный характер 
int main()
{
    int first = 12;
    int second = 123;
    int thert = 1234;

	t_list *head;
    if((head = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    head->data  = &first;
    head->next  = (t_list*)malloc(sizeof(t_list));
    head->next->data = &second;
    head->next->next  = (t_list*)malloc(sizeof(t_list));
    head->next->next->data = &thert;
    head->next->next->next = NULL;
    printf("pointer for last element of the list : %p \n",ft_list_last(head));
    free(head);
    ft_print_list(head);
    
	return (0);
}