#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


/*
Function name       ft_lstadd_front
Prototype           void ft_lstadd_front(t_list **lst, t_list *new);
Turn in files -
Parameters          #1. The address of a pointer to the first link of
                    a list.
                    #2. The address of a pointer to the element to be
                    added to the list.
Return value        None
External functs.    None
Description         Adds the element ’new’ at the beginning of the
list.
*/


typedef struct s_list
{
    void *content;
    struct s_list *next;
}   t_list;

//то что помогает печатать список
void ft_print_list(t_list *head)
{
    t_list *current = head;
    printf(" pointer to begin: %p \n", head);
    while(current != NULL)
    {   
        printf(" begin->next: %p\n" , current->next);
        printf(" begin->content: %d\n" , *((int*)current->content));
        current = current->next;
    }    
    
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    lst=&new; 
}

// функция main носит чисто проверочный характер проверяя то что в начало связанного списка действительно добавляются новые структуры
int main()
{
    int first = 3;
    int second = 5;
    

	t_list *current;
    t_list *begin;
    if((current = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    current->content  = &first;
    current->next  = NULL;

    if((begin = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    begin->content = &second;  
    begin->next  = NULL; 
    ft_lstadd_front(&current, begin);
    ft_print_list(begin);

    free(current);
    free(begin);
	return (0);
}

