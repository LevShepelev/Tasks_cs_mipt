#include <stdio.h>
int main()
    {
    int i = 0;
    char s[1000] = {'\0'};
    int a[10] = {0};
    FILE* fin = fopen("tasks.txt", "a+");
    for (i = 0; i < 10; i++)
	{
	fprintf(fin, "%5d", (i + 9)*(i + 9));
	}
    fseek(fin, 0L, SEEK_SET);
    i = 0;
    s[i] = getc(fin);
    while (s[i] != EOF)
	{
	printf("%c", s[i]);
	i++;
	s[i] = getc(fin); 
	}
    fclose(fin);
    }
