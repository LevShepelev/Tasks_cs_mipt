#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* convert(char * dst, const char * src);
//Функция переводит из восьмеричной системы счисления в двоичную методом триад
char* convert(char * dst, const char * src)
    {
    int dec = 0, i = 0, n = 0, j = 0, k = 0;
    if ( src[0] == '0')
        {
        printf("ERROR\n");
        return NULL;
        }
    for (i = 0; src[i] != '\0'; i++)
        ;
    n = i - 1;
    dst[3*i + 1] = '\0';
    for (i = n + 1; i > 0; i--)
        {
        switch (src[i - 1])
            {
            case '0':
                dst[3*i] = '0';
                dst[3*i - 1] = '0';
                dst[3*i - 2] = '0';
                break;
            case '1':
                dst[3*i] = '1';
                dst[3*i - 1] = '0';
                dst[3*i - 2] = '0';
                break;
            case '2':
                dst[3*i] = '0';
                dst[3*i - 1] = '1';
                dst[3*i - 2] = '0';
                break;
            case '3':
                dst[3*i] = '1';
                dst[3*i - 1] = '1';
                dst[3*i - 2] = '0';
                break;
            case '4':
                dst[3*i] = '0';
                dst[3*i - 1] = '0';
                dst[3*i - 2] = '1';
                break;
            case '5':
                dst[3*i] = '1';
                dst[3*i - 1] = '0';
                dst[3*i - 2] = '1';
                break;
            case '6':
                dst[3*i] = '0';
                dst[3*i - 1] = '1';
                dst[3*i - 2] = '1';
                break;
            case '7':
                dst[3*i] = '1';
                dst[3*i - 1] = '1';
                dst[3*i - 2] = '1';
                break;
            default:
                printf("ERROR\n");
                return NULL;
            } 
        } 
    i = 1;
    while (dst[i] == '0')
        i++;
    return (dst + i);
    }


int main(int argc, char* argv[])
    {
    if (strlen(argv[1]) > 100)
        {
        printf("ERROR");
        return -1;
        }
    char* res = (char*) calloc (strlen(argv[1]) * 3, sizeof(char));
    char* free_buf = res;
    res = convert(res, argv[1]);
    for (int i = 0; i < strlen(res); i++)
        printf("%c", res[i]);
    free(free_buf);
    }