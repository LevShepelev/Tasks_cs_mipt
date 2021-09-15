#include <stdio.h>
int calc (int a, int b)
    {
    int x = a;
    for (int i = 1; i < b; i++)
        {
        a = a * x;
        }
    return a;
    }
int main()
    {
    printf("%d", calc(2,4));
    }