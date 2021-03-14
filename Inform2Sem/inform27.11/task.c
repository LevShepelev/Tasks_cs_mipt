#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct line{
char *s1;
char *s2;
int n;
int m;
} Line;

void func(Line* l1)
    {
    int i = 0;
    l1 -> s2 = (char*) calloc(l1 -> m, sizeof(char));
    scanf("%s", l1 -> s2);
    strncpy(((l1 -> s1) + 1), ((l1 -> s2) + 4), 3);
    }
int main()
    {
    int i = 0;
    Line l1;
    scanf("%d%d", &(l1.m), &(l1.n));
    l1.s1 = (char*) calloc(l1.n + 1, sizeof(char));
    scanf("%s", l1.s1);
    func(&l1);
    printf("%s", l1.s1);
    }