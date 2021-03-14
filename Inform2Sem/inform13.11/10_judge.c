
#include <stdio.h>
#include <stdlib.h>
struct _Decimal{char* a; unsigned int n;};
typedef struct _Decimal Decimal;

void big_print (Decimal* res);
Decimal* add(const Decimal* s1, const Decimal* s2);

Decimal* half(const Decimal* ch1);

Decimal* half(const Decimal* ch1)
	{
	int i, b = 0;
    Decimal* res1 = calloc(1, sizeof(Decimal));
    res1 -> a = calloc((ch1 -> n + 2), sizeof(char));
	for (i = ch1 -> n; i >= 0; i--)
		{
		(*(res1 -> a + i)) = (*(ch1 -> a + i) + 10 * b) / 2;
		b = (*(ch1 -> a + i)) % 2;
		}
	if ((*(res1 -> a + (ch1 -> n))) == 0) 
		res1 -> n = ch1 -> n - 1;
	else 
		res1 -> n = ch1 -> n;
    return (res1);
	}


Decimal* add(const Decimal* s1, const Decimal* s2)
    {
    Decimal* res = (Decimal*) calloc (1, sizeof(Decimal));
    res -> a = (char*) calloc (s1 -> n + s1 -> n + 2, sizeof(char));
    int i = 0, b = 0;
    if ((s1 -> n) < (s2 -> n)) 
        {
        for (i = 0; i <= s1 -> n; i++)
            {
            (res -> a)[i] = ((s1 -> a)[i] + (s2 -> a)[i] + b) % 10;
            b = ((s1 -> a)[i] + (s2 -> a)[i] + b) / 10;
            }
        if (s1 -> n == s2 -> n)
            (res -> a)[i] = b;
        for (i = s1 -> n + 1; i <= s2 -> n; i++)
            {
            (res -> a)[i] = ((s2 -> a)[i] + b) % 10;
            b = ((s2 -> a)[i] + b) / 10;
            }
        if ((res -> a)[i] > 0)
            res -> n = i;
        else res -> n = i -1;
        }
    else 
        {
        for (i = 0; i <= s2 -> n; i++)
            {
            (res -> a)[i] = ((s2 -> a)[i] + (s1 -> a)[i] + b) % 10;
            b = ((s2 -> a)[i] + (s1 -> a)[i] + b) / 10;
            }
        if (s1 -> n == s2 -> n)
            (res -> a)[i] = b;
        for (i = s2 -> n + 1; i <= s1 -> n; i++)
            {
            (res -> a)[i] = ((s1 -> a)[i] + b) % 10;
            b = ((s1 -> a)[i] + b) / 10;
            }
        if ((res -> a)[i] > 0)
            res -> n = i;
        else res -> n = i - 1;
        }
    return res;
    }
void elong_free(Decimal** res)
    {
    printf("%p  %p\n", (*res) -> a, (*res));
    free((*res) -> a);
    free(*res);
    printf("%p  %p\n", (*res) -> a, (*res));
    }
void big_print (Decimal* res)
    {
    printf("printing\nres = ");
    for (int i = 0; i <= res -> n; i++)
        printf("%d", *(res -> a + res -> n - i));
    printf("\n res -> n =%d", res -> n);
    }
int main()
    {
    //char f[100] = {9, 4, 5, 6, 1, 9};
    char t[50] = {9, 4, 9, 5, 6, 7, 8, 8, 9};
    char g[50] = {9, 5, 6, 1, 3, 9, 4, 2, 1};
    Decimal s1 = {t, 8};
    Decimal s2 = {g, 8}; 
    big_print(add(&s1, &s2));
    }