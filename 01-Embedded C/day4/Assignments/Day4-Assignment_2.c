/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 4----------------------------------------------------*/

/*----------------------------------------------------Assignment 1----------------------------------------------------*/
/*Write a C code that define 3 int variables x, y and z and 3 pointers to int p, q and r.
 Set x, y, z to three distinct values. Set p, q, r to the addresses of x, y, z respectively.
a- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
b- Print the message: Swapping pointers.
c- Execute the swap code: r = p; p = q; q = r;
d- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.*/

#include <stdio.h>
#define size 10

void main(void)
{
    // decleration
    int x, y, z;
    int *p, *q, *r;

    // initialization
    x = 50, y = 30, z = 20;

    p = &x, q = &y, r = &z;

    // Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
    printf("x=%d,y=%d,z=%d\np=%p,q=%p,r=%p\n*p=%d, *q=%d, *r=%d", x, y, z, p, q, r, *p, *q, *r);
    printf("\nSwapping pointers....");
    int *temp = r;
    r = p;
    p = q;
    q = temp;
    printf("\nx=%d,y=%d,z=%d\np=%p,q=%p,r=%p\n*p=%d, *q=%d, *r=%d", x, y, z, p, q, r, *p, *q, *r);
}
