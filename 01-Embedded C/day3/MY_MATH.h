void PrintInstructions()
{
    printf("ID | Operation  | Number of Operands\n"
           "0  | Exit       | :(\n"
           "1  | Add        | 2\n"
           "2  | Subtract   | 2\n"
           "3  | Multiply   | 2\n"
           "4  | Divide     | 2\n"
           "5  | And        | 2\n"
           "6  | Or         | 2\n"
           "7  | Not        | 1\n"
           "8  | Xor        | 2\n"
           "9  | Reminder   | 2\n"
           "10 | Increment  | 1\n"
           "11 | Decrement  | 1\n"
           "12 | For inst   | 1\n\n");
}

int addFunc(int op1, int op2)
{
    return op1 + op2;
}

int subtractFunc(int op1, int op2)
{
    return op1 - op2;
}

int multiplyFunc(int op1, int op2)
{
    return op1 * op2;
}

float divideFunc(int op1, int op2)
{
    return (float)op1 / op2;
}

int andFunc(int op1, int op2)
{
    return op1 & op2;
}
int orFunc(int op1, int op2)
{
    return op1 | op2;
}
int notFunc(int op1)
{
    return !op1;
}
int xorFunc(int op1, int op2)
{
    return op1 ^ op2;
}
int reminderFunc(int op1, int op2)
{
    return op1 % op2;
}
int incrementFunc(int op1)
{
    return ++op1;
}
int decrementFunc(int op1)
{
    return --op1;
}
