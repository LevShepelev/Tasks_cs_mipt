#include <stdio.h>
#include <stdlib.h>

typedef struct hasht {char flag; int key; char* data;} hash_t;
typedef struct tablet {hash_t* table; int size;} table_t;
const int m = 101;

int hash(int key);
void HashPrint(table_t t1);
char* search(table_t t1);
void delete(table_t* t1);
void insert(table_t* t1);


int hash(int key)
    {
    return (key % m);
    }

void insert(table_t* t1)
    {  
    int password = 0, i = 0;
    scanf("%d", &password);
    i = hash(password);
    while ((t1 -> table)[i].flag != 0)
        {
        if (i == t1 -> size)
            {
            t1 -> table = realloc(t1 -> table, t1 -> size + m);
            t1 -> size = t1 -> size + m;
            }
        i++;
        }
    (t1 -> table)[i].key = password;
    scanf("%s", (t1 -> table)[i].data);
    (t1 -> table)[i].flag = 1;
    }

char* search(table_t t1)
    {
    int password = 0, i = 0;
    scanf("%d", &password);
    i = hash(password);
    while ((t1.table[i].key != password) && (i < t1.size))
        i++;
    if (i == t1.size)  
        {
        printf("element did not found");
        return ("\0");
        }
    return (t1.table[i].data);
    }

void delete(table_t* t1)
    {
    int password = 0, i = 0;
    scanf("%d", &password);
    i = hash(password);
    while (((t1 -> table)[i].key != password) && (i < t1 -> size))
        i++;
    if (i == t1 -> size)  
        {
        printf("element did not found");
        }
    (t1 -> table)[i].flag = 0;
    (t1 -> table)[i].data[0] = '\0';
    (t1 -> table)[i].key = 0;
    }
void HashPrint(table_t t1)
    {
    int i = 0;
    for (i = 0; i < t1.size; i++)
        printf("i = %d, key = %d, data = %s\n", i, t1.table[i].key, t1.table[i].data);
    }

int main()
    {
    int i = 0, manage = 0;
    table_t t1;
    t1.table = (hash_t*) calloc(m, sizeof(hash_t));
    t1.size = m;
    for (i = 0; i < m; i++)
        {
        t1.table[i].flag = 0;
        t1.table[i].data = (char*) calloc(20, sizeof(char));
        }
    do 
        {
        printf("Enter action number\n0 - finishing program\n1 - insert\n2 - search\n3 - delete\n4 - HashPrint\n");
        scanf("%d", &manage);
        if (manage == 1) insert (&t1);
        if (manage == 2) printf ("%s\n", search(t1));
        if (manage == 3) delete (&t1);
        if (manage == 4) HashPrint(t1);
        }
    while (manage != 0);
    return 0;
    }