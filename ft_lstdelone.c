#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


/*
Function name           ft_lstdelone
Prototype               void ft_lstdelone(t_list *lst, void (*del)(void
                        *));
Turn in files           -
Parameters              #1. The element to free.
                        #2. The address of the function used to delete the
                        content.
Return value            None
External functs.        free
Description             Takes as a parameter an element and frees the
                        memory of the element’s content using the function
                        ’del’ given as a parameter and free the elemen
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
    while(current != NULL)
    {   
        printf(" begin->next: %p\n" , current->next);
        printf(" begin->content: %d\n" , *((int*)current->content));
        current = current->next;
    }    
    
}
void ft_free(void *pointer)
{
    free(pointer);
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    del(lst);
}

// функция main носит чисто проверочный характер проверяя то что в начало связанного списка действительно добавляются новые структуры
int main()
{
    int first = 3;
    int second = 5;
    

	t_list *current;
    if((current = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return(1);
    current->content  = &second;
    current->next  = (t_list*)malloc(sizeof(t_list));
    current->next->content = &first;
    current->next->next=NULL;

    ft_lstdelone(current->next, &ft_free);
    ft_print_list(current);

    free(current);
	return (0);
}

