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
        printf(" pointer of node: %p , data: %s \n", current->next, ((char*)current->data));
        current = current->next;
    }    
    
}
//функция которая добавляет элемент в начало связанного списка
void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new;
    
    if ((new = (t_list*)malloc(sizeof(t_list))) != ((void *)0))
    {
        new->data = data;
        new->next = *begin_list; 
        *begin_list = new;
    }
    else
        printf("this functhion can't reserv memory for new structur");
}


t_list *ft_list_push_strs(int size, char **strs)
{
    int i = 1;
    t_list *head;

    if ((head = (t_list*)malloc(sizeof(t_list)*size)) != ((void *)0))
    {
        head->data = strs[0];
        head->next = NULL;

        while(i<size)
        {
            ft_list_push_front(&head, strs[i]);
            i++;    
        }
    }
    else
        printf("this functhion can't reserv memory for new structur");
    return(head);
    
}

// функция main носит чисто проверочный характер 
int main()
{
    int len = 3;

    char *str[] = {"AAA","BBB","CCC"};
    t_list *head = ft_list_push_strs(len,str);
    free(head);
    ft_print_list(head);
    
	return (0);
}

