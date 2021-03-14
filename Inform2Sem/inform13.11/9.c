#include <stdio.h>
int main()
    {
    int a[20][2] = {0};
    int i = 0, j = 0;
    FILE* fin = fopen("text9", "w+");
    for (i = 0; i < 20; i++)
    	{
	for (j = 0; j < 4; j++)
	     {
	     fprintf(fin, "%4d", (4*i - j*j)); 
	     }
	fprintf(fin,"\n");
	}
    fseek(fin, 0L, SEEK_SET);
    for (i = 0; i < 20; i++)
	{
        fscanf(fin, "%*d%d%*d%d", &(a[i][0]), &(a[i][1]));
 	}
    fclose(fin);
    FILE* fout = fopen("text9out", "w");
    for (i = 0; i < 20; i++)
	{
	fprintf(fout, "%4d%4d\n", a[i][0], a[i][1]);
	}
    fclose(fout);
    }
