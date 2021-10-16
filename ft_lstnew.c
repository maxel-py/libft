#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


/*
Function name       ft_lstnew
Prototype           t_list *ft_lstnew(void *content);
Turn in files -
Parameters          #1. The content to create the new element with.
Return value        The new element.
External functs.    malloc

Description Allocates (with malloc(3)) and returns a new
element. The variable ’content’ is initialized
with the value of the parameter ’content’. The
variable ’next’ is initialized to NULL.
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
    while(current != NULL)
    {   
        printf(" pointer of current node: %p , next node %p, data: %d \n", current, current->next, *((int*)current->content));
        current = current->next;
    }    
    
}

//создает первый элемент нового списка и передает туда дату

t_list *ft_lstnew(void *content)
{
    t_list *head;

    if((head = (t_list*)malloc(sizeof(t_list))) == ((void *)0))
        return((void*)0);
    head -> content = content;
    head -> next = (void*)0;

    return(head);

}

// функция main носит чисто проверочный характер 
int main()
{
    int first = 12;

    t_list *pointer = ft_lstnew((void *)(&first));
    ft_print_list(pointer);
	return (0);
}

