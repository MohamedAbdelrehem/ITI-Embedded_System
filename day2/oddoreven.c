#include <stdio.h>

void main()
{
    int x;
    scanf("%d", &x);

    if ((x & 1) == 0)
    {
        printf("even");
    }
    else
    {
        printf("odd");
    }
}