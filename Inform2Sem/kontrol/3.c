#include <stdio.h>
#include <stdlib.h>
struct woman {
        int grud;
        int tal;
        int bedra;
        int sum;
};
typedef struct woman Woman;
int my_cmp(const void* val1, const void* val2);


int my_cmp(const void* val1, const void* val2)
    {
    if ((((Woman*)val1) -> sum) > (((Woman*)val2) -> sum)) return 1;
    if ((((Woman*)val1) -> sum) < (((Woman*)val2) -> sum)) return -1;
    if ((((Woman*)val1) -> sum) == (((Woman*)val2) -> sum))
        {
        if ((((Woman*)val1) -> grud) > (((Woman*)val2) -> grud)) return -1;
        if ((((Woman*)val1) -> grud) < (((Woman*)val2) -> grud)) return 1;
        if ((((Woman*)val1) -> grud) == (((Woman*)val2) -> grud))
            {
            if ((((Woman*)val1) -> tal) > (((Woman*)val2) -> tal)) return 1;
            if ((((Woman*)val1) -> tal) < (((Woman*)val2) -> tal)) return -1;
            if ((((Woman*)val1) -> tal) == (((Woman*)val2) -> tal))
                {
                if ((((Woman*)val1) -> bedra) > (((Woman*)val2) -> bedra)) return -1;
                if ((((Woman*)val1) -> bedra) < (((Woman*)val2) -> bedra)) return 1;
                if ((((Woman*)val1) -> bedra) == (((Woman*)val2) -> bedra)) return 0;
                }
            }
        }
    return 0;
    }

int main()
    {
    Woman mass[1000];
    int n = 0, i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        {
        scanf("%d %d %d", &(mass[i].grud), &(mass[i].tal), &(mass[i].bedra));
        mass[i].sum = mass[i].grud + mass[i].tal + mass[i].bedra;
        }
    qsort((void*)mass, n, sizeof(Woman), my_cmp); 
    for (i = 0; i < n; i++)
        printf("%d %d %d\n", mass[i].grud,  mass[i].tal,  mass[i].bedra);
    return 0;
    }