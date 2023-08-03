#include <stdio.h>

void main()
{
    int x;
    scanf("%d", &x);

    if (x >= 0 && x < 50)
    {
        printf("F");
    }
    else if (x >= 50 && x < 65)
    {
        printf("N");
    }
    else if (x >= 65 && x < 75)
    {
        printf("G");
    }
    else if (x >= 75 && x < 85)
    {
        printf("VG");
    }
    else if (x >= 85 && x <= 100)
    {
        printf("ex");
    }
    else
    {
        printf("Wrong Number");
    }
}