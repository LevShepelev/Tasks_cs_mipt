#include <stdio.h>
#include <stdlib.h>
int search (int* arr, int b, int n, int* copy)
    {
    if (n == 2) return (arr - copy + n / 2); 
    if ((b >= arr[n / 2]) && (b <= arr[n / 2 + 1])) return (arr - copy + n / 2);
    if (b > arr[n / 2]) return search(arr + n / 2, b, n / 2, copy);
    if (b < arr[n / 2]) return search(arr, b, n / 2, copy);
    }
int main()
    {
    int b = 0, i, n;
    scanf("%d", &n);
    int* arr = (int*) calloc (n, sizeof(int));
    for (i = 0; i < n; i++)
	{
	printf("arr[%d] = ", i);
        scanf("%d", arr + i);
	}
    printf("input number b\n");
    scanf("%d", &b);
    printf("i = %d", search(arr, b, n, arr));
    }
