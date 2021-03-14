#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
    {
    int i = 0, s = 0;
    char* end = NULL;
    //printf("argc = %d\n", argc);
    for (i = 1; i < argc; i++)
    	    {
	    s += strtol(argv[i], end, 10);
	    printf("%ld\n", strtol(argv[i], &end, 10));
	    printf("%s", *end);
	    }
    return s;
    }
