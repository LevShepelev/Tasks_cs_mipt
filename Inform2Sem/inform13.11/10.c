#include <stdio.h>
struct Decimal{char a[100]; unsigned int n;};


void big_mulpliticat(struct Decimal ch1, int k, struct Decimal* res)
    {
    int i = 0, b = 0;
    for (i = 0; i < ch1.n; i++)
		{
		(*res).a[i] = (((ch1.a[i] - '0') * k + b) % 10 + '0');
		b = ((ch1.a[i] - '0') * k + b)/ 10;
		}
    (*res).n = i;
    if (b != 0)
		{
		(*res).a[ch1.n] = b + '0';
        (*res).n++;
		}
    }



void big_division(struct Decimal ch1, int k, struct Decimal* res1)
	{
	int i, b = 0;
	printf("decimal_starts\n");
	for (i = ch1.n - 1; i >= 0; i--)
		{
		res1->a[i] = (ch1.a[i] - '0' + 10 * b) / k + '0';
		printf("res1[%d] = %c\t", i, (*res1).a[i]);
		b = (ch1.a[i] - '0') % k;
		}
	if (res1->a[ch1.n - 1] == '0') 
		{
		printf("happend");
		res1->n = ch1.n - 1;
		}
	else 
		res1->n = ch1.n;
	}



int main()
    {
    int i, k = 0;
	char temp;
    struct Decimal ch1 = {'\0', 0};
    struct Decimal res = {'\0', 0};
	struct Decimal res1 = {'\0', 0};
    scanf("%s%d", ch1.a, &k);

    while ((ch1.a)[ch1.n] != '\0')
		ch1.n++;
	for (i = 0; i < ch1.n / 2; i++)
		{
		temp = ch1.a[i];
		ch1.a[i] = ch1.a[ch1.n - i - 1];
		ch1.a[ch1.n - i - 1] = temp;
		}
	for (i = 0; i < ch1.n; i++)
		printf("ch1.a[%d] = %c\t", i, ch1.a[i]);

    big_mulpliticat(ch1, k, &(res));
    for (i = 0; i < res.n; i++)
		printf("%c", res.a[res.n - i - 1]);

	   big_division(ch1, k, &res1);
	      printf("\n division result \n ");
	for (i = 0; i < res.n; i++)
		printf("%c", res1.a[res1.n - i - 1]);
    }
