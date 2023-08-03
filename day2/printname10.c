#include <stdio.h>

void main()
{
    // for(int i =0;i<10;i++){
    //     // printf("Mohamed\n");
    //     printf("%d\n",i+1);
    // }
    // printf("enter the 10 numbers\n");
    // int sum = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     int val;
    //     printf("Number %d : ", i + 1);
    //     scanf("%d", &val);
    //     sum += val;
    // }
    // double avg = (double)sum / 10;
    // printf("avarage = %f", avg);

    int var;
    scanf("%d", &var);
    int counter = var;
    while (counter > 1)
    {

        counter--;
        var *= counter;
    }
    printf("%d", var);
}