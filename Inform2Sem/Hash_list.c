#include <stdio.h>
#include <stdlib.h>

typedef struct hashnode {int key; char* data; struct hashnode *next;} Hashnode;
const int m = 11;

void delete(Hashnode** table);
void insert(Hashnode** table);
char* search(Hashnode** table);
int hash(int key);
void HashPrint(Hashnode** table);


int hash(int key)
    {
    return (key % m);
    }

void insert(Hashnode** table)
    {
    int password = 0;
    scanf("%d", &password);
    char* s = (char*) calloc (20, sizeof(char));
    scanf("%19s", s);
    Hashnode* current = table[hash(password)];
    Hashnode* prev;
    if (current == NULL)
        {
        current = (Hashnode*) malloc (sizeof(Hashnode));
        table[hash(password)] = current;
        current -> next = NULL;
        current -> key = password;
        current -> data = s;
        return;
        }
    if (current != NULL) 
        {
        while (current != NULL)
            {
            prev = current;
            current = current -> next;
            }
        current = (Hashnode*) malloc (sizeof(Hashnode));
        prev -> next = current;
        current -> next = NULL;
        current -> key = password;
        current -> data = s;
        }
    }

char* search(Hashnode** table)
    {
    int password;
    scanf("%d", &password);
    Hashnode* current = table[hash(password)];
    while (current != NULL)
        {
        if (current -> key == password)
            return (current -> data);
        else current = current -> next;
        }
    printf("element not found");
    return("\0");
    }
void HashPrint(Hashnode** table)
    {
    for (int i = 0; i < m; i++)
        printf("%p\n", table[i]);
    }

void delete(Hashnode** table)
    {
    int password = 0;
	scanf("%d", &password);
    Hashnode* curr = table[hash(password)];
	Hashnode* prev;
    if (curr == NULL)
        {
        printf("element haven't found");
        return;
        }
    if ((curr -> next == NULL) && (curr -> key == password))
        {
        free(curr -> data);
        free(curr);
        table[hash(password)] = NULL;
        return;
        }
    while (curr -> key != password) 
        {
        prev = curr;
        curr = curr -> next;
        if (curr == NULL)
            {
            printf("element haven't found");
            return;
            }
        }
    prev -> next = curr -> next;
    free(curr->data);
    free(curr);
    }

int main()
    {
    int i = 0, manage;
    Hashnode** table = (Hashnode**) calloc(m, sizeof(Hashnode*));
    for (i = 0; i < m; i++)
        {
        table[i] = NULL;
        }
    do 
        {
        printf("Enter action number\n0 - finishing program\n1 - insert\n2 - search\n3 - delete\n4 - HashPrint\n");
        scanf("%d", &manage);
        if (manage == 1) insert (table);
        if (manage == 2) printf ("%s\n", search(table));
        if (manage == 3) delete (table);
        if (manage == 4) HashPrint(table);
        }
    while (manage != 0);
    free(table);
    return 0;
    }