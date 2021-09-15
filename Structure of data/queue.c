#include <stdio.h>
#include <stdlib.h>
         
typedef int Item;
typedef struct node {
                    Item elem;
                    struct node *next;
                    } Node;
typedef struct queue {
                     Node *front;
                     Node *rear;
                     int items;
                     } Queue;

Queue* queue_construct();
void queue_push(Queue* q1);
Item queue_pop(Queue** q1);
void queue_clear(Queue* q1);
void queue_print(Queue* q1);
int  queue_check(Queue* q1);
void delete_queue(Queue** q1);


int main()
    {
    int i = 0;
    Queue* q1 = queue_construct();
    queue_print(q1);
    for (i = 0; i < 4; i++)
        printf("popped = %d\n", queue_pop(&q1));
    queue_push(q1);
    queue_pop(&q1);
    queue_print(q1);
    delete_queue(&q1);
    queue_print(q1);
    }
Queue* queue_construct()
	{
    int i = 0, n = 0;
    Node *current;
    Queue* q1 = (Queue*) calloc (1, sizeof(Queue));
    printf("queue constuction, enter number of elements, then values\n");
    scanf("%d", &n);
    printf("enter th pushing value\n");
    current = (Node*) malloc (sizeof(Node));
    scanf("%d",&(current -> elem));
    current -> next = NULL;
    q1 -> front = current;
    q1 -> rear = current;
    q1 -> items = 1;
    for (i = 1; i < n; i++)
        {
        queue_push(q1);
        current = current -> next;
        }
    return q1;
	}
void queue_push(Queue* q1)
    {
    if (queue_check(q1) == 1) return;
    Node* current;
	current = (Node*) malloc (sizeof(Node));
    (q1 -> rear) -> next = current;
    current -> next = NULL;
    printf("enter the pushing value\n");
	scanf("%d", &(current -> elem));
    q1 -> items++;
    q1 -> rear = current;
    }
Item queue_pop(Queue** q1)
    {
    Item a;
    Node* temp;
    if (queue_check(*q1) == 1) return;
    if ((*q1) -> items == 0)
        {
        printf("Queue is empty\n");
        return;
        }
    a = ((*q1) -> front) -> elem;
    temp = ((*q1) -> front) -> next;
    free ((*q1) -> front);
    (*q1) -> front = temp;
    (*q1) -> items--;
    return a;
    }
void queue_clear(Queue* q1)
    {
    if (queue_check(q1) == 1) return;
    int i = 0;
    for (i = 0; i < q1 -> items; i++)
        queue_pop(&q1);
    }
void queue_print(Queue* q1)
    {
    if (queue_check(q1) == 1) return;
    Node* current = q1 -> front;
    int i = 0;
    printf("Queue Printing\nq1 adress = %p\nq1 -> front = %p\nq1 -> rear = %p\nq1 -> items = %d\nqueue from the beggining\n", q1, q1 -> front, q1 -> rear, q1 -> items);
    for (i = 0; i < q1 -> items; i++)
        {
        printf("%d number [%d]\n", current -> elem, i + 1);
        current = current -> next;
        }
    }
int  queue_check(Queue* q1)
    {
    if (q1 == NULL) 
        {
        printf("Queue was deleted");
        return 1;
        }
    }
void delete_queue(Queue** q1)
    {
    if (queue_check(*q1) == 1) return;
    int i = 0;
    for (i = 0; i < (*q1) -> items; i++)
        queue_pop(q1);
    free(*q1);
    *q1 = NULL;
    }
