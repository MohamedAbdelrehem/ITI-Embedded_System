// 1234-> Ahmed
// "78 -> Youssef
// 1145 Mina

#include <stdio.h>

void main()
{
    int id;
    scanf("%d", &id);
    switch (id)
    {
    case 1234:
        printf("Welcome Ahmed");
        break;
    case 5678:
        printf("Welcome Youssef");
        break;
    case 1145:
        printf("Welcome Mina");
        break;
    default:
        printf("Wrong ID");
    }
}