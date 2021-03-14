#include <stdio.h>
#include <stdlib.h>
typedef struct list{int elem; struct list* next;} List;
void list_delete_first(List** head)
	{
	List* temp = (*head);
	(*head) = (*head) -> next;
	free(temp);
	}

int main()
    {
    int i;
    List  *current, *prev;
    List* head = NULL;
    for (i = 1; i <= 41; i++)
        {
        current = (List*) malloc (sizeof(List));
        if (head == NULL) 
			head = current;
        else 
            {
            prev -> next = current;
			}
        current -> next = NULL; 
        current -> elem = i;
        prev = current;
        if (i == 41)
            current -> next = head;
        }
    while ((head -> next) -> next != head)
        {
        printf("%d\n", ((head -> next) -> next) -> elem);
        list_delete_first(&((head -> next) -> next));
        head = (head -> next) -> next;
        }
    printf("Answer: %d  %d", head -> elem, (head -> next) -> elem);
    /*while (head != NULL)
        {
        printf("%d\n", head -> elem);
        head -> next;
        }*/
    }