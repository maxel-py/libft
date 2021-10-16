#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
/*
Function name       ft_lstsize
Prototype           int ft_lstsize(t_list *lst);
Turn in files 
                    Parameters #1. The beginning of the list.
Return              value Length of the list.
External functs.    None
Description         Counts the number of elements in a list.
*/

typedef struct s_list
{
    void *content;
    struct s_list *next;
}   t_list;

// то что помогает распечатать связанный список 
void ft_print_list(t_list *head)
{
    t_list *current = head;
    printf(" head: %p \n", head);
    while(current != NULL)
    {   
        printf(" pointer of node: %p , data: %d \n", current->next, *((int*)current->content));
        current = current->next;
    }    
    
}

int ft_lstsize(t_list *lst)
{
    int i = 0;
    while(lst != NULL)
    {
        i++;
        lst=lst->next;
    }
    return(i);
}

// функция main носит чисто проверочный характер проверяя то что в начало связанного списка действительно добавляются новые структуры
int main()
{
    int first = 12;
    int second = 123;
    int thert = 1234;

	t_list *head;
    if((head = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    head->content  = &first;
    head->next  = (t_list*)malloc(sizeof(t_list));
    head->next->content = &second;
    head->next->next  = (t_list*)malloc(sizeof(t_list));
    head->next->next->content = &thert;
    head->next->next->next = NULL;
    printf("result work size function is : %d \n",ft_lstsize(head));
    free(head);
    
	return (0);
}