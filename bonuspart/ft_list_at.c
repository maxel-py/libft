#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include"ft_list.h"

// то что помогает распечатать связанный список 
void ft_print_list(t_list *head)
{
    t_list *current = head;
    while(current != NULL)
    {   
        printf(" pointer of node: %p , data: %d \n", current->next, *((int*)current->data));
        current = current->next;
    }    
    
}

//возвращает указанный элемент последовательности передаваемый в качестве аргумента 
//причем нулевой элемент это фактически первый элемент списка

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *current = begin_list;

    if (begin_list==(void*)0)
        return(begin_list);
    else
    {
        t_list *current = begin_list;
        unsigned int i = 0;
        while(i < nbr)
        {
            current = current -> next;
            i++;
        }
    }
    return(current);

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
    
    ft_print_list(ft_list_at(head, 0));
    free(head);
    
	return (0);
}

