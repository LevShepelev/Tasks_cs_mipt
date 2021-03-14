#include <stdio.h>
#include <stdlib.h>
int main()
    {
    int i = 0;
    FILE* fin = fopen("tasks.txt", "w");
    char a[10] = {'2', '3', '5', '1', '6', '8', '1', '1', '1', '9'};
    for (i = 0; i < 10; i++)
    	{
	fprintf(fin, "%c", a[i]);
	}
    fclose(fin);
    }
