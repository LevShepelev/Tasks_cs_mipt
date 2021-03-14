#include <stdio.h>
#include <stdlib.h>
int main()
    {
    int i, n = 0;
    scanf("%d", &n);
    int* arr = (int*) calloc (n, sizeof(int));
    for (i = 0; i < n; i++)
	scanf("%d", arr + i);
    for (i = 0; i < n; i++)
	printf("%d\n", *(arr + i));
    }
