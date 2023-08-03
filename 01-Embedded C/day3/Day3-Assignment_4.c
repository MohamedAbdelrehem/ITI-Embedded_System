/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 3----------------------------------------------------*/

/*----------------------------------------------------Assignment 4----------------------------------------------------*/
/*Write C code that manage a small school. The school has 3 classes each class
contains 10 students. Define three arrays for the three classes each one with a
length of 10. Save a random numbers in all array elements to indicate the
students grade. The program will calculate and display the following statistics:
1- Number of passed students
2- Number of Failed students
3- Highest grade
4- Lowest grade
5- Average grade
Knowing that the total grade is from 100 and the minimum passing grade is 50.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define No_Classes 3
#define No_Students 10

int max_min(int val, int *max, int *min)
{
    if (val > *max)
    {
        *max = val;
    }
    if (val < *min)
    {
        *min = val;
    }
}

void main(void)
{
    // Seed the random number generator so it is diff
    srand(time(NULL));
    // Define three arrays for the three classes
    int grades[No_Classes][No_Students];

    // set data with rand bec why not :)
    for (int class_num = 0; class_num < No_Classes; class_num++)
    {
        printf("Grades for Class %d: ", class_num + 1);
        for (int student = 0; student < No_Students; student++)
        {
            grades[class_num][student] = rand() % 101;
            printf("%d ", grades[class_num][student]);
        }
        printf("\n");
    }

    int passCounter = 0, failedCounter = 0, maxGrade = 0, lowGrade = 101, sumOfGrades = 0;

    for (int class_num = 0; class_num < No_Classes; class_num++)
    {
        for (int student = 0; student < No_Students; student++)
        {
            // count failed Students
            if (grades[class_num][student] >= 50)
            {
                passCounter++;
            }
            else
            {
                failedCounter++;
            }

            // get highest and lowest grade
            max_min(grades[class_num][student], &maxGrade, &lowGrade);
            // sum all grades for avarage
            sumOfGrades += grades[class_num][student];
        }
    }
    // calculate avrage
    int avg = sumOfGrades / (No_Classes * No_Students);

    // print all :)
    printf("\nNumber of passed students is: %d\nNumber of Failed students is: %d\nHighest grade is: %d\nLowest grade is: %d\nAverage grade is: %d", passCounter, failedCounter, maxGrade, lowGrade, avg);
}
