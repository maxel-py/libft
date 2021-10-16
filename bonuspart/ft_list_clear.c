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

void ft_free(void *pointer)
{
    free(pointer);
}


// вылазиет ошибка, и не понятно как трактовать, то ли все линки и данные удалены поэтому не выводит на печать, но скорее всего где то ошибка, реализация с гита один в один

//a.out(32633,0x1065a45c0) malloc: *** error for object 0x7ffeecfd4618: pointer being freed was not allocated
//a.out(32633,0x1065a45c0) malloc: *** set a breakpoint in malloc_error_break to debug
//Abort trap: 6

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *current = begin_list;
    t_list *tmp;
    while(current != NULL)
    {
        tmp = current;
        free(tmp);
        if(current->data)
            free_fct(current->data);
        current = current->next;
    }
    begin_list = NULL;

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
    ft_print_list(head);
    ft_list_clear(head, ft_free);
    ft_print_list(head);

	return (0);
}

