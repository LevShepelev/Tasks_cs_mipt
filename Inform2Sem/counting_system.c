#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Функция переводит число из любой системы счисления в любую (до 36-ричной)
char* count_system_changing(char* str, int first_sys, int second_sys)
    {
    const int ascii_shift = 7;
    char buf;
    char* res = (char*) calloc (100, sizeof(char));
    int length = strlen(str);
    int i = 0, temp = 0;
    unsigned long long int_part = 0;

    for (i = 0; i < length; i++)
        {
        if (!(((str[i] >= '0') && (str[i] <= '9')) || ((str[i] >= 'A') && (str[i] <= 'A' - 10 + first_sys))))
            {
            printf("Input error\n");
            return NULL;
            }
        if (first_sys > 10)
            temp = ascii_shift;
        else temp = 0;
        if ((str[i] >= first_sys + '0' + temp) || (str[i] > 'Z'))
            {
            printf("Input error\n");
            return NULL;
            }
        }
    for (i = 0; i < length; i++)
        {
        if (str[length - i - 1] > '9') 
            temp = ascii_shift;
        else temp = 0;
        int_part += pow(first_sys, i) * (str[length - i - 1] - '0' - temp);
        if (int_part >= pow(2, 63)) printf  ("Input error: Too big number\n");
        }
    i = 0;
    while (int_part / second_sys > 0)
        {
        if (int_part % second_sys > 9)
            temp = ascii_shift;
        else temp = 0;
        res[i] = int_part % second_sys + '0' + temp;
        i++;
        int_part /= second_sys;
        } 
    if (int_part % second_sys > 9)
            temp = ascii_shift;
        else temp = 0;
    res[i] = int_part % second_sys + '0' + temp;
    int len1 = strlen(res);
    for (i = 0; i < len1 / 2; i++)
        {
        buf = res[i];
        res[i] = res[len1 - i - 1];
        res[len1 - i - 1] = buf;
        }
    return res;
    }

int main()
    {
    int first_sys = 0, second_sys = 0, i = 0, comma_pos = 0;
    scanf("%d", &first_sys);
    scanf("%d", &second_sys);
    char str[100];
    scanf("%s", str);
    char* res = count_system_changing(str, first_sys, second_sys);
    printf("Result :%s\n", res);
    free(res);
    return 0;
    }