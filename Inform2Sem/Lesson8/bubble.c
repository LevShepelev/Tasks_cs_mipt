#include <stdio.h>
int main()
    {
    int a[10] = {-2, 3, 4, 1, -3, 4, 5, 1, -33, 4};
    int i = 0, j = 0;
    for (i = 0; i < 10; i++)
        for (j = 9; j > i; j--)
            if (a[j] < a[j - 1])
                {
                int buf = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buf;
                }
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    }