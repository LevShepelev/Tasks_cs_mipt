#include <stdio.h>
#include <stdlib.h>
int main()
    {
    int i = 0;
    int a[10] = {0};
    FILE* fin = fopen("tasks.txt", "w+");
    for (i = 0; i < 10; i++)
	{
	fprintf(fin, "%5d", i*i);
	}
    fseek(fin, 0L, SEEK_SET);
    for (i = 0; i < 10; i++)
	{
	fscanf(fin, "%5d", (a + i));
	printf("a[%d] = %d\n", i, a[i]);
	}
    printf("number of bytes = %d", ftell(fin));
    fclose(fin);
    }

