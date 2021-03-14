#include <stdio.h>
#include <stdlib.h>
         
typedef struct list{int elem; struct list* next;} List;

void list_print(List* head)
	{
	int i = 0;
	printf("printing has started\n");
	if (head == NULL) 
		{
		printf("list was destructed\n");
		return;
		}
	List* current = head;
	while (current != NULL)
		{
		printf("list[%d] = %d  %p\n", i, current -> elem, current -> next);
		current = current -> next;
		i++;
		}
	}
void list_construct(List** head, int n)
	{
    int i;
    List  *current, *prev;
	if (*head != NULL)
		{
		printf("List was constructed earlier\n");
		return;
		}
    for (i = 0; i < n; i++)
        {
        current = (List*) malloc (sizeof(List));
        if (*(head) == NULL) 
			*(head) = current;
        else 
            {
            prev -> next = current;
			}
        current -> next = NULL; 
        scanf("%d",&(current -> elem));
        prev = current;
		}
	}

void list_add_end(List** head)
	{
	List* current = *head, *prev;
	while (current != NULL)
		{
		prev = current;
		current = current -> next;
		}
	current = (List*) malloc (sizeof(List));
	prev -> next = current;
	current -> next = NULL;
	scanf("%d", &(current -> elem));
	}
	
void list_add_start(List** head)
	{ 
	List* current;
	current = (List*) malloc(sizeof(List));
	current -> next = (*head);
	*head = current;
	scanf("%d", &(current -> elem));
	}


void list_add_before_value(List** head, int n)
	{
	int flag = 0;
    List* temp;
	List* prev;
    List* current = *head;
    while (current -> elem != n)
    	{
        prev = current;
        current = current -> next;
        if (current == NULL)
			{
            printf("The entered did not found");
            flag = 1;
            break;
			}
        }
    if (flag == 0)
        {
        temp = current;
		current = (List*) malloc (sizeof(List));
		scanf("%d", &(current -> elem));
		current -> next = temp;
		prev -> next = current;
		}
	}		


void list_add_after_value(List** head, int n)
	{
	int flag = 0;
    List* temp;
    List* current = *head;
    while (current -> elem != n)
    	{
        current = current -> next;
        if (current == NULL)
      		{  
            printf("The entered did not found\n");
            flag = 1;
            break;
            }
        }
	if (flag == 0)
		{
		temp = (List*) malloc (sizeof(List));
		scanf("%d", &(temp -> elem));
		temp -> next = current -> next;
		current -> next = temp;
		}
	}

void list_delete_first(List** head)
	{
	List* temp = (*head);
	(*head) = (*head) -> next;
	free(temp);
	}

void list_delete_last(List** head)
	{
	List* curr = *head;
	List* prev;
	while (curr -> next != NULL)
		{
		prev = curr;
		curr = curr -> next;
		}
	free(curr);
	prev -> next = NULL;
	}

void list_delete_element(List** head)
	{
	int n = 0;
	List* curr = (*head);
	List* prev;
	scanf("%d", &n);
	do 
		{
		prev = curr;
		curr = curr -> next;
		if (curr == NULL)
			{
			printf("element not found");
			return;
			}
		} while (curr -> elem != n);
	prev -> next = curr -> next;
	free(curr);
	}

void list_print_to_file(List* head)
	{
	int i = 0;
	FILE* fout = fopen("List.txt", "w");
	List* curr = head;
	while (curr != NULL)
		{
		fprintf(fout, "list[%d] = %d  %p\n", i, curr -> elem, curr -> next);
		curr = curr -> next;
		i++;
		}
	fclose (fout);
	}

void list_destruct(List** head)
	{
	List* prev;
	List* curr = *head;
	while (curr != NULL)
		{
		prev = curr; 
		curr = curr -> next;
		free(prev);
		}
	*head = NULL;
	}
		
int main ()
	{
	int i, n, request, capacity, flag_exit = 0;
	List *head = NULL;
	char menu[500] = "Menu\nchoose action\n\
	case 0: List construct, enter number of elements, and values\n\
	case 1: List printing\n\
	case 2: Addiing the element in the end of list, enter value of element\n\
	case 3: Adding element to the begging of list, enter the value\n\
	case 4: Adding before value\n\
	case 5: Adding after value\n\
	case 6: Deleting first element\n\
	case 7: Deleting last element\n\
	case 8: Deleting elemen\n\
	case 9 Printing list to file\n\
	case 10 List destruction\n\
	case 11: Finishing the program\n\0";

	printf("Welcome to the List editor\n");
	printf("%s", menu);

	while (flag_exit != 1)
		{
		scanf("%d", &request);
		switch(request)
			{
			case 0:
				printf("case 0: enter capacity and values\n");
				scanf("%d", &capacity);
				list_construct(&head, capacity);
				printf("%s", menu);
				break;
			case 1:
				printf("case 1: printing\n");
				list_print(head);
				printf("%s", menu);
				break;
			case 2:
				printf("case 2: enter value\n");
				list_add_end(&head);
				printf("%s", menu);
				break;
			case 3:
				printf("case 3: enter value\n");
				list_add_start(&head);
				printf("%s", menu);
				break;
			case 4:
				printf("case 4: enter the searched element, then enter element\n");
				scanf("%d", &n);
				list_add_before_value(&head, n);
				printf("%s", menu);
				break;
			case 5:
				printf("case 5: enter the searched element, then enter element\n");
				scanf("%d", &n);
				list_add_after_value(&head, n);
				printf("%s", menu);
				break;
			case 6:
				printf("case 6: delete first element\n");
				list_delete_first(&head);
				printf("%s", menu);
				break;
			case 7:
				printf("case 7: delete lash element\n");
				list_delete_last(&head);
				printf("%s", menu);
				break;
			case 8:
				printf("case 8: delete element, enter the element\n");
				list_delete_element(&head);
				printf("%s", menu);
				break;
			case 9:
				printf("case 9: printing list to file\n");
				list_print_to_file(head);
				printf("%s", menu);
				break;
			case 10:
				printf("case 10: list destruct\n");
				list_destruct(&head);
				printf("%s", menu);
				break;
			case 11:
				flag_exit = 1;
				head = NULL;
				break;
			default:
				printf("incorrect input\n");
			}
		}
	return 0;
	}
