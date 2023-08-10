/*
Name:Mohamed Abdelrehem Ali
ITI: "G1"

/*---------------------------------------------------- DAY 6----------------------------------------------------*/

/*----------------------------------------------------Assignment 2----------------------------------------------------*/
/*Complex Number*/
#include <stdio.h>
#include "STD_TYPES.h" // Include your STD_TYPES.h header

// Define a struct for complex numbers using your typedefs
struct Complex
{
    f32 real;
    f32 imaginary;
};

// Function to add two complex numbers
struct Complex add(struct Complex a, struct Complex b)
{
    struct Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex a, struct Complex b)
{
    struct Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex a, struct Complex b)
{
    struct Complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

// Function to divide two complex numbers
struct Complex divide(struct Complex a, struct Complex b)
{
    struct Complex result;
    f32 denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

// Function to display a complex number bec why not :)
void display(struct Complex num)
{
    if (num.imaginary >= 0)
    {
        printf("%.2f + %.2fi\n", num.real, num.imaginary);
    }
    else
    {
        printf("%.2f - %.2fi\n", num.real, -num.imaginary);
    }
}

int main()
{
    struct Complex num1, num2;

    // Input values for num1
    printf("Enter real and imaginary parts of Complex Number 1: ");
    scanf("%f %f", &num1.real, &num1.imaginary);

    // Input values for num2
    printf("Enter real and imaginary parts of Complex Number 2: ");
    scanf("%f %f", &num2.real, &num2.imaginary);

    printf("\nComplex Number 1: ");
    display(num1);

    printf("Complex Number 2: ");
    display(num2);

    struct Complex sum = add(num1, num2);
    printf("Sum: ");
    display(sum);

    struct Complex difference = subtract(num1, num2);
    printf("Difference: ");
    display(difference);

    struct Complex product = multiply(num1, num2);
    printf("Product: ");
    display(product);

    struct Complex Divide = divide(num1, num2);
    printf("Divide: ");
    display(Divide);

    return 0;
}
