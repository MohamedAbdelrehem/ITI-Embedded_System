#include <stdio.h>
#include <stdlib.h>

void MyBubbleSort(int *arrToSort, int arrSize);

void main(void)
{
    int arrSize;
    scanf("%d", &arrSize);

    int *arr = (int *)malloc(arrSize * sizeof(int));

    // enter the numbers
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }

    MyBubbleSort(arr, arrSize);
}

void MyBubbleSort(int *arrToSort, int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int temp = 0;
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arrToSort[j] > arrToSort[j + 1])
            {
                temp = arrToSort[j];
                arrToSort[j] = arrToSort[j + 1];
                arrToSort[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arrToSort[i]);
    }
}