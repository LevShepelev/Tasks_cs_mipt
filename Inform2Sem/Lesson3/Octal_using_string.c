#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert_octal(char** bin, char* argv)
    {
    int shift = 0, i = 0;
    const char s_cod[50] = "/0-000/1-001/2-010/3-011/4-100/5-101/6-110/7-111";
    if ((argv[0] < '1') || (strlen(argv) >= 100) || (argv[0] > '7'))
        {
        printf("INPUT ERROR\n");
        exit (1);
        }
    if (argv[0] < '2')
        {
        shift = 2;
        (*bin) = (char*) calloc (strlen(argv) * 3 - 1, sizeof(char));
        (*bin)[0] = '1'; 
        }
    else if (argv[0] < '4')
        {
        shift = 1;
        (*bin) = (char*) calloc (strlen(argv) * 3, sizeof(char));
        (*bin)[0] = '1';
        (*bin)[1] = argv[0] - 2;
        }
    else 
        {
        (*bin) = (char*) calloc (strlen(argv) * 3 + 1, sizeof(char));
        strncpy((*bin) - shift, s_cod + (argv[0] - '0') * 6 + 3, 3);
        }
    

    for (i = 1; i < strlen(argv); i++)
        {
        if ((argv[i] < '0') || (argv[i] > '7'))
            {
            printf("INPUT ERROR, not a number\n");
            exit (1);
            } 
        strncpy((*bin) + 3 * i - shift, s_cod + (argv[i] - '0') * 6 + 3, 3);
        }
    (*bin)[3 * i - shift] = '\0';
    }

int main(int argc, char* argv[])
    {
    char* res;
    convert_octal(&res,  argv[1]);
    printf("%s\n", res);
    free (res);
    }