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

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new;
    
    if ((new = (t_list*)malloc(sizeof(t_list))) != ((void *)0))
    {
        new->data = (int*)data;
        new->next = *begin_list; 
        *begin_list = new;
    }
    else
        printf("this functhion can't reserv memory for new structur");
}

// функция main носит чисто проверочный характер проверяя то что в начало связанного списка действительно добавляются новые структуры
int main()
{
    int first = 3;
    int second = 2;
    int thert = 1;

	t_list *head;
    if((head = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    head->data  = &first;
    head->next  = NULL;

    ft_list_push_front(&head,&first);
    ft_list_push_front(&head,&second);
    ft_list_push_front(&head,&thert);
    free(head);
    ft_print_list(head);
    
	return (0);
}