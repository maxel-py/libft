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

void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *current = *begin_list;
    while(current->next != NULL)
    {
        current=current->next;
    }
    
    if ((current->next  = (t_list*)malloc(sizeof(t_list))) != ((void *)0))
    {
        current -> next -> data = data;
        current -> next -> next = NULL; 
    }
    else
        printf("this functhion can't reserv memory for new structur");
}

// функция main носит чисто проверочный характер проверяя то что в КОНЕЦ связанного списка действительно добавляются новые структуры
int main()
{
    int first = 1;
    int second = 8;

	t_list *head;
    if((head = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    head->data  = &first;
    head->next  = (t_list*)malloc(sizeof(t_list));
    head->next->data  = &first;
    head->next->next = NULL;

    ft_list_push_back(&head,&second);
    ft_list_push_back(&head,&second);
    free(head);
    ft_print_list(head);
    
	return (0);
}